from __future__ import annotations

import argparse
import re
import shlex
import sys
import time
from pathlib import Path
from typing import Sequence

import numpy as np
import numpy.typing as npt

from airfoil import apply_naca_airfoil
from sovler import FLUID, set_over_relaxation


FloatArray = npt.NDArray[np.float32]
StructuredCellArray = npt.NDArray[np.void]
WATERMARK_TEXT = "Tejas Bishnoi github.com/TejasBishnoi"


def slugify_run_name(value: str) -> str:
    slug = re.sub(r"[^A-Za-z0-9._-]+", "-", value.strip()).strip("-._")
    return slug or "run"


def build_run_output_dir(base_dir: Path, run_name: str | None) -> Path:
    timestamp = time.strftime("%Y%m%d_%H%M%S")
    suffix = slugify_run_name(run_name) if run_name else "run"
    output_dir = base_dir / f"{timestamp}_{suffix}"
    output_dir.mkdir(parents=True, exist_ok=False)
    return output_dir


def write_cli_summary(path: Path, parser: argparse.ArgumentParser, args: argparse.Namespace) -> None:
    lines: list[str] = []
    lines.append("Command used")
    lines.append("------------")
    lines.append(" ".join(shlex.quote(part) for part in [sys.executable, Path(sys.argv[0]).name, *sys.argv[1:]]))
    lines.append("")
    lines.append("Selected values")
    lines.append("---------------")
    for key in sorted(vars(args)):
        lines.append(f"{key} = {getattr(args, key)!r}")
    lines.append("")
    lines.append("Available CLI arguments")
    lines.append("-----------------------")
    for action in parser._actions:
        if action.dest == "help":
            continue
        option_names = ", ".join(action.option_strings) if action.option_strings else action.dest
        default_repr = "" if action.default is argparse.SUPPRESS else f" | default={action.default!r}"
        choices_repr = f" | choices={tuple(action.choices)!r}" if action.choices is not None else ""
        metavar_repr = ""
        if action.metavar is not None:
            metavar_repr = f" | metavar={action.metavar!r}"
        elif action.nargs not in (None, 0):
            metavar_repr = f" | nargs={action.nargs!r}"
        help_text = action.help or ""
        lines.append(f"{option_names}{metavar_repr}{default_repr}{choices_repr}")
        if help_text:
            lines.append(f"  {help_text}")
    lines.append("")
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


class HeadlessWindTunnel:
    def __init__(
        self,
        grid_w: int = 200,
        grid_h: int = 100,
        density: float = 1.0,
        flow_speed: float = 9.0,
        smoke_strength: float = 1.0,
        gravity: float = 0.0,
        dt: float = 0.08,
        iterations: int = 30,
        over_relax: float = 1.9,
        inlet_columns: int = 3,
    ) -> None:
        self.grid_w = grid_w
        self.grid_h = grid_h
        self.density = density
        self.flow_speed = flow_speed
        self.smoke_strength = smoke_strength
        self.gravity = gravity
        self.dt = dt
        self.iterations = iterations
        self.over_relax = over_relax
        self.inlet_columns = inlet_columns

        self.fluid: FLUID
        self._create_scene()

    def _idx(self, i: int, j: int) -> int:
        return i * self.fluid.numY + j

    def _reshape_field(self, field: FloatArray) -> FloatArray:
        return field.reshape(self.fluid.numX, self.fluid.numY)

    def _create_scene(self) -> None:
        self.fluid = FLUID(self.density, self.grid_w, self.grid_h, 1.0)
        self.fluid.s.fill(0.0)
        self.fluid.m.fill(0.0)
        self.fluid.u.fill(0.0)
        self.fluid.v.fill(0.0)
        self.fluid.p.fill(0.0)
        self._reshape_field(self.fluid.s)[1:-1, 1:-1] = 1.0

        self.apply_inlet()

    def apply_inlet(self) -> None:
        center = self.grid_h // 2 + 1
        half_height = max(4, self.grid_h // 6)
        low = center - half_height
        high = center + half_height
        inlet = slice(1, self.inlet_columns + 1)
        interior = slice(1, self.fluid.numY - 1)
        band = slice(low, high + 1)

        s = self._reshape_field(self.fluid.s)
        u = self._reshape_field(self.fluid.u)
        v = self._reshape_field(self.fluid.v)
        m = self._reshape_field(self.fluid.m)

        s[inlet, interior] = 1.0
        u[inlet, interior] = self.flow_speed * 0.25
        m[inlet, interior] = self.smoke_strength * 0.08
        u[inlet, band] = self.flow_speed
        m[inlet, band] = self.smoke_strength
        v[inlet, interior] = 0.0

    def set_obstacle_circle(self, cx: int, cy: int, radius: int, solid: bool = True) -> None:
        for i in range(max(1, cx - radius), min(self.fluid.numX - 1, cx + radius + 1)):
            for j in range(max(1, cy - radius), min(self.fluid.numY - 1, cy + radius + 1)):
                if (i - cx) * (i - cx) + (j - cy) * (j - cy) > radius * radius:
                    continue
                if i <= self.inlet_columns + 1:
                    continue
                idx = self._idx(i, j)
                if solid:
                    self.fluid.s[idx] = 0.0
                    self.fluid.m[idx] = 0.0
                    self.fluid.u[idx] = 0.0
                    self.fluid.v[idx] = 0.0
                else:
                    self.fluid.s[idx] = 1.0

    def set_obstacle_mask(self, mask: npt.NDArray[np.bool_], solid: bool = True) -> None:
        if mask.shape != (self.grid_w, self.grid_h):
            raise ValueError(f"mask shape {mask.shape} does not match grid {(self.grid_w, self.grid_h)}")

        clipped_mask = mask.copy()
        clipped_mask[: self.inlet_columns + 1, :] = False
        occupied = np.argwhere(clipped_mask)
        for i0, j0 in occupied:
            i = int(i0) + 1
            j = int(j0) + 1
            idx = self._idx(i, j)
            if solid:
                self.fluid.s[idx] = 0.0
                self.fluid.m[idx] = 0.0
                self.fluid.u[idx] = 0.0
                self.fluid.v[idx] = 0.0
            else:
                self.fluid.s[idx] = 1.0

    def set_obstacle_parametric(
        self,
        shape: str,
        center_x: float,
        center_y: float,
        width: float,
        height: float,
        angle_of_attack_deg: float = 0.0,
    ) -> None:
        x = np.arange(1, self.grid_w + 1, dtype=np.float32) - np.float32(center_x)
        y = np.arange(1, self.grid_h + 1, dtype=np.float32) - np.float32(center_y)
        xx, yy = np.meshgrid(x, y, indexing="ij")

        theta = np.deg2rad(np.float32(angle_of_attack_deg))
        cos_t = np.cos(theta, dtype=np.float32)
        sin_t = np.sin(theta, dtype=np.float32)
        xr = cos_t * xx + sin_t * yy
        yr = -sin_t * xx + cos_t * yy

        half_w = max(np.float32(width) * np.float32(0.5), np.float32(1.0))
        half_h = max(np.float32(height) * np.float32(0.5), np.float32(1.0))
        abs_xr = np.abs(xr)
        abs_yr = np.abs(yr)
        width_safe = max(np.float32(width), np.float32(1.0))
        height_safe = max(np.float32(height), np.float32(1.0))

        if shape == "ellipse":
            mask = (xr / half_w) ** 2 + (yr / half_h) ** 2 <= 1.0
        elif shape == "square":
            side = min(half_w, half_h)
            mask = (abs_xr <= side) & (abs_yr <= side)
        elif shape == "rectangle":
            mask = (abs_xr <= half_w) & (abs_yr <= half_h)
        elif shape == "diamond":
            mask = abs_xr / half_w + abs_yr / half_h <= 1.0
        elif shape == "triangle":
            nose = half_w
            tail = -half_w
            within_x = (xr >= tail) & (xr <= nose)
            taper = np.clip((nose - xr) / width_safe, 0.0, 1.0)
            mask = within_x & (abs_yr <= half_h * taper)
        elif shape == "triangle_down":
            mask = (abs_xr / half_w + np.clip(yr / half_h, -1.0, 1.0) <= 1.0) & (yr >= -half_h) & (yr <= half_h)
        elif shape == "triangle_up":
            mask = (abs_xr / half_w + np.clip(-yr / half_h, -1.0, 1.0) <= 1.0) & (yr >= -half_h) & (yr <= half_h)
        elif shape == "capsule":
            body_half = max(half_w - half_h, np.float32(0.0))
            rect = (abs_xr <= body_half) & (abs_yr <= half_h)
            left_cap = (xr + body_half) ** 2 + yr**2 <= half_h**2
            right_cap = (xr - body_half) ** 2 + yr**2 <= half_h**2
            mask = rect | left_cap | right_cap
        elif shape == "twin_circle":
            offset = max(half_h * np.float32(0.9), np.float32(1.5))
            radius = max(min(half_w, half_h), np.float32(1.0))
            upper = xr**2 + (yr - offset) ** 2 <= radius**2
            lower = xr**2 + (yr + offset) ** 2 <= radius**2
            bridge = (abs_xr <= radius * np.float32(0.45)) & (abs_yr <= offset)
            mask = upper | lower | bridge
        elif shape == "plus":
            arm = min(half_w, half_h) * np.float32(0.45)
            mask = ((abs_xr <= arm) & (abs_yr <= half_h)) | ((abs_xr <= half_w) & (abs_yr <= arm))
        elif shape == "diamond_cut":
            outer = abs_xr / half_w + abs_yr / half_h <= 1.0
            inner = abs_xr / max(half_w * np.float32(0.45), np.float32(1.0)) + abs_yr / max(
                half_h * np.float32(0.45), np.float32(1.0)
            ) <= 1.0
            mask = outer & (~inner)
        elif shape == "venturi":
            channel_half = half_h
            throat_half = max(channel_half * np.float32(0.55), np.float32(2.0))
            x_norm = np.clip(abs_xr / half_w, 0.0, 1.0)
            opening = throat_half + (channel_half - throat_half) * x_norm**1.4
            wall_band = max(height_safe * np.float32(0.18), np.float32(2.0))
            upper_wall = (yr >= opening) & (yr <= opening + wall_band)
            lower_wall = (yr <= -opening) & (yr >= -opening - wall_band)
            mask = (abs_xr <= half_w) & (upper_wall | lower_wall)
        elif shape == "notched_square":
            side = min(half_w, half_h)
            outer = (abs_xr <= side) & (abs_yr <= side)
            notch_w = max(side * np.float32(0.45), np.float32(1.0))
            notch_h = max(side * np.float32(0.35), np.float32(1.0))
            notch = (abs_xr <= notch_w) & (abs_yr <= notch_h)
            mask = outer & (~notch)
        elif shape == "trapezoid":
            top_half = max(half_w * np.float32(0.45), np.float32(1.0))
            blended_half = top_half + (half_w - top_half) * ((yr + half_h) / height_safe)
            mask = (yr >= -half_h) & (yr <= half_h) & (abs_xr <= blended_half)
        else:
            raise ValueError(f"unsupported parametric shape: {shape}")

        self.set_obstacle_mask(mask.astype(bool, copy=False), solid=True)

    def set_obstacle_airfoil(
        self,
        naca_code: str,
        chord_length: float,
        center_x: float,
        center_y: float,
        angle_of_attack_deg: float = 0.0,
    ) -> npt.NDArray[np.float64]:
        return apply_naca_airfoil(
            self.fluid,
            naca_code=naca_code,
            chord_length=chord_length,
            center_x=center_x,
            center_y=center_y,
            angle_of_attack_deg=angle_of_attack_deg,
        )

    def step(self, steps: int = 1) -> None:
        set_over_relaxation(self.over_relax)

        for _ in range(steps):
            self.apply_inlet()
            self.fluid.integrate_g(self.dt, self.gravity)
            self.fluid.p.fill(0.0)
            self.fluid.incompressibility_solve(self.iterations, self.dt)
            self.fluid.Extrapolate()
            self.fluid.advection_vel(self.dt)
            self.fluid.advection_smoke(self.dt)
            self.apply_inlet()

    def speed_field(self) -> FloatArray:
        u = self._reshape_field(self.fluid.u)
        v = self._reshape_field(self.fluid.v)
        half = np.float32(0.5)
        u_center = (u[1:-1, 1:-1] + u[2:, 1:-1]) * half
        v_center = (v[1:-1, 1:-1] + v[1:-1, 2:]) * half
        speed = np.empty_like(u_center, dtype=np.float32)
        np.sqrt(u_center * u_center + v_center * v_center, out=speed)
        return speed.T

    def smoke_field(self) -> FloatArray:
        return self._reshape_field(self.fluid.m)[1:-1, 1:-1].T.copy()

    def pressure_field(self) -> FloatArray:
        return self._reshape_field(self.fluid.p)[1:-1, 1:-1].T.copy()

    def solid_field(self) -> FloatArray:
        return (1.0 - self._reshape_field(self.fluid.s)[1:-1, 1:-1]).T.astype(np.float32, copy=False)

    def export_cell_data(self) -> StructuredCellArray:
        n = self.fluid.numY
        u = self._reshape_field(self.fluid.u)
        v = self._reshape_field(self.fluid.v)
        s = self._reshape_field(self.fluid.s)
        m = self._reshape_field(self.fluid.m)
        p = self._reshape_field(self.fluid.p)

        i_idx, j_idx = np.indices((self.grid_w, self.grid_h), dtype=np.int32)
        i_cells = i_idx + 1
        j_cells = j_idx + 1

        u_face = u[1:-1, 1:-1]
        v_face = v[1:-1, 1:-1]
        half = np.float32(0.5)
        u_center = (u_face + u[2:, 1:-1]) * half
        v_center = (v_face + v[1:-1, 2:]) * half
        speed = np.empty_like(u_center, dtype=np.float32)
        np.sqrt(u_center * u_center + v_center * v_center, out=speed)

        cell_data = np.empty(
            self.grid_w * self.grid_h,
            dtype=[
                ("cell_id", np.int32),
                ("i", np.int32),
                ("j", np.int32),
                ("s", np.float32),
                ("u_face", np.float32),
                ("v_face", np.float32),
                ("u_center", np.float32),
                ("v_center", np.float32),
                ("speed", np.float32),
                ("smoke", np.float32),
                ("pressure", np.float32),
            ],
        )
        cell_data["cell_id"] = (i_cells * n + j_cells).reshape(-1)
        cell_data["i"] = i_cells.reshape(-1)
        cell_data["j"] = j_cells.reshape(-1)
        cell_data["s"] = s[1:-1, 1:-1].reshape(-1)
        cell_data["u_face"] = u_face.reshape(-1)
        cell_data["v_face"] = v_face.reshape(-1)
        cell_data["u_center"] = u_center.reshape(-1)
        cell_data["v_center"] = v_center.reshape(-1)
        cell_data["speed"] = speed.reshape(-1)
        cell_data["smoke"] = m[1:-1, 1:-1].reshape(-1)
        cell_data["pressure"] = p[1:-1, 1:-1].reshape(-1)
        return cell_data


def save_cell_csv(path: Path, cell_data: StructuredCellArray) -> None:
    header = "cell_id,i,j,s,u_face,v_face,u_center,v_center,speed,smoke,pressure"
    matrix = np.column_stack(
        [
            cell_data["cell_id"],
            cell_data["i"],
            cell_data["j"],
            cell_data["s"],
            cell_data["u_face"],
            cell_data["v_face"],
            cell_data["u_center"],
            cell_data["v_center"],
            cell_data["speed"],
            cell_data["smoke"],
            cell_data["pressure"],
        ]
    )
    np.savetxt(path, matrix, delimiter=",", header=header, comments="", fmt="%.6f")


def save_field_plot(
    path: Path,
    speed: FloatArray,
    smoke: FloatArray,
    pressure: FloatArray,
    solid: FloatArray,
    watermark_text: str = WATERMARK_TEXT,
) -> None:
    import matplotlib

    matplotlib.use("Agg")
    import matplotlib.pyplot as plt

    fig, axes = plt.subplots(2, 2, figsize=(12, 8), constrained_layout=True)
    plots: Sequence[tuple[FloatArray, str, str]] = (
        (smoke, "Smoke", "gray"),
        (speed, "Speed Magnitude", "viridis"),
        (pressure, "Pressure", "coolwarm"),
        (solid, "Solid Mask", "binary"),
    )

    for ax, (field, title, cmap) in zip(axes.ravel(), plots):
        image = ax.imshow(field, origin="lower", cmap=cmap, aspect="auto")
        ax.set_title(title)
        ax.set_xlabel("i")
        ax.set_ylabel("j")
        fig.colorbar(image, ax=ax, shrink=0.85)

    fig.suptitle("Flow Report")
    fig.text(0.99, 0.012, watermark_text, ha="right", va="bottom", fontsize=9, color="0.25")
    fig.savefig(path, dpi=180)
    plt.close(fig)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Run the flow simulation and export only the final-state results."
    )
    parser.add_argument("--resolution", nargs=2, type=int, metavar=("NX", "NY"), default=(200, 100))
    parser.add_argument("--hardstep", type=int, default=400)
    parser.add_argument("--min-steps", type=int, default=100)
    parser.add_argument("--steady-tol", type=float, default=1e-4)
    parser.add_argument("--iterations", type=int, default=30)
    parser.add_argument("--dt", type=float, default=0.08)
    parser.add_argument("--flow-speed", type=float, default=9.0)
    parser.add_argument("--smoke-strength", type=float, default=1.0)
    parser.add_argument("--gravity", type=float, default=0.0)
    parser.add_argument("--over-relax", type=float, default=1.9)
    parser.add_argument("--inlet-columns", type=int, default=3)
    parser.add_argument(
        "--solid-shape",
        choices=(
            "airfoil",
            "circle",
            "ellipse",
            "square",
            "rectangle",
            "diamond",
            "triangle",
            "triangle_up",
            "triangle_down",
            "trapezoid",
            "capsule",
            "twin_circle",
            "plus",
            "diamond_cut",
            "notched_square",
            "venturi",
        ),
        default="airfoil",
    )
    parser.add_argument("--naca-code", type=str, default="2412")
    parser.add_argument("--chord-length", type=float, default=30.0)
    parser.add_argument("--circle-radius", type=int, default=12)
    parser.add_argument("--center", nargs=2, type=float, metavar=("X", "Y"), default=(70.0, 51.0))
    parser.add_argument("--angle-of-attack", type=float, default=0.0)
    parser.add_argument("--run-name", type=str, default=None)
    parser.add_argument("--output-dir", type=str, default="outputs")
    return parser


def main() -> None:
    parser = build_parser()
    args = parser.parse_args()

    grid_w, grid_h = int(args.resolution[0]), int(args.resolution[1])
    center_x, center_y = float(args.center[0]), float(args.center[1])

    sim = HeadlessWindTunnel(
        grid_w=grid_w,
        grid_h=grid_h,
        iterations=int(args.iterations),
        dt=float(args.dt),
        flow_speed=float(args.flow_speed),
        smoke_strength=float(args.smoke_strength),
        gravity=float(args.gravity),
        over_relax=float(args.over_relax),
        inlet_columns=int(args.inlet_columns),
    )
    if args.solid_shape == "circle":
        sim.set_obstacle_circle(
            cx=int(round(center_x)),
            cy=int(round(center_y)),
            radius=int(args.circle_radius),
            solid=True,
        )
    elif args.solid_shape in {
        "ellipse",
        "square",
        "rectangle",
        "diamond",
        "triangle",
        "triangle_up",
        "triangle_down",
        "trapezoid",
        "capsule",
        "twin_circle",
        "plus",
        "diamond_cut",
        "notched_square",
        "venturi",
    }:
        sim.set_obstacle_parametric(
            shape=str(args.solid_shape),
            center_x=center_x,
            center_y=center_y,
            width=float(args.chord_length),
            height=float(args.circle_radius) * 2.0,
            angle_of_attack_deg=float(args.angle_of_attack),
        )
    else:
        sim.set_obstacle_airfoil(
            str(args.naca_code),
            chord_length=float(args.chord_length),
            center_x=center_x,
            center_y=center_y,
            angle_of_attack_deg=float(args.angle_of_attack),
        )

    output_dir = build_run_output_dir(Path(args.output_dir), args.run_name)
    write_cli_summary(output_dir / "cli_cmd.txt", parser, args)

    max_steps = int(args.hardstep)
    min_steps = int(args.min_steps)
    steady_tol = float(args.steady_tol)
    previous_speed: FloatArray | None = None
    residual_history: list[tuple[int, float]] = []

    start = time.perf_counter()
    steps_run = max_steps

    for step in range(1, max_steps + 1):
        sim.step(1)
        speed = sim.speed_field()

        if previous_speed is not None:
            residual = float(np.max(np.abs(speed - previous_speed)))
            residual_history.append((step, residual))
            if step == 2 or step % 10 == 0:
                print(f"step {step}/{max_steps} | max_speed_change={residual:.6e}", flush=True)
            if residual < steady_tol and step >= min_steps:
                steps_run = step
                print(
                    f"steady state reached at step {step} | max_speed_change={residual:.6e}",
                    flush=True,
                )
                break
        elif step == 1:
            print(f"step {step}/{max_steps} | initializing flow field", flush=True)

        previous_speed = speed.copy()

    if steps_run == max_steps:
        print(f"max steps reached without meeting steady tolerance {steady_tol:.1e}", flush=True)

    elapsed = time.perf_counter() - start

    speed = sim.speed_field()
    smoke = sim.smoke_field()
    pressure = sim.pressure_field()
    solid = sim.solid_field()
    cell_data = sim.export_cell_data()

    save_cell_csv(output_dir / "airfoil_cells.csv", cell_data)
    save_field_plot(output_dir / "airfoil_fields.png", speed, smoke, pressure, solid, watermark_text=WATERMARK_TEXT)

    if residual_history:
        np.savetxt(
            output_dir / "residual_history.csv",
            np.array(residual_history, dtype=np.float64),
            delimiter=",",
            header="step,max_speed_change",
            comments="",
            fmt="%.6f",
        )

    print(f"steps: {steps_run}")
    print(f"elapsed_seconds: {elapsed:.3f}")
    print(f"steps_per_second: {steps_run / elapsed:.2f}")
    print(f"max_speed: {float(np.max(speed)):.3f}")
    print(f"mean_smoke: {float(np.mean(smoke)):.3f}")
    print(f"output_dir: {output_dir.resolve()}")


if __name__ == "__main__":
    main()
