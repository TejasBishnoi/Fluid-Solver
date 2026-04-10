import argparse
import sys
import time
from pathlib import Path

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np

from airfoilgen import apply_naca_airfoil
print("Made By - Tejas Bishnoi. Github: github.com/TejasBishnoi . instagram: @whoistejas")
sys.modules.setdefault("visualizer", sys.modules[__name__])


class cur_SEC:
    cur_sec = {"OverRelax": 1.9}


from sovler import FLUID


class HeadlessWindTunnel:
    def __init__(
        self,
        grid_w=200,
        grid_h=100,
        density=1.0,
        flow_speed=9.0,
        smoke_strength=1.0,
        gravity=0.0,
        dt=0.08,
        iterations=30,
        over_relax=1.9,
        inlet_columns=3,
    ):
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

        self._create_scene()

    def _idx(self, i, j):
        return i * self.fluid.numY + j

    def _create_scene(self):
        self.fluid = FLUID(self.density, self.grid_w, self.grid_h, 1.0)
        self.fluid.s.fill(0.0)
        self.fluid.m.fill(0.0)
        self.fluid.u.fill(0.0)
        self.fluid.v.fill(0.0)
        self.fluid.p.fill(0.0)

        for i in range(1, self.fluid.numX - 1):
            for j in range(1, self.fluid.numY - 1):
                self.fluid.s[self._idx(i, j)] = 1.0

        self.apply_inlet()

    def apply_inlet(self):
        center = self.grid_h // 2 + 1
        half_height = max(4, self.grid_h // 6)
        low = center - half_height
        high = center + half_height

        for i in range(1, self.inlet_columns + 1):
            for j in range(1, self.fluid.numY - 1):
                idx = self._idx(i, j)
                self.fluid.s[idx] = 1.0
                if low <= j <= high:
                    self.fluid.u[idx] = self.flow_speed
                    self.fluid.m[idx] = self.smoke_strength
                else:
                    self.fluid.u[idx] = self.flow_speed * 0.25
                    self.fluid.m[idx] = self.smoke_strength * 0.08
                self.fluid.v[idx] = 0.0

    def set_obstacle_circle(self, cx, cy, radius, solid=True):
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

    def set_obstacle_airfoil(self, naca_code, chord_length, center_x, center_y):
        return apply_naca_airfoil(
            self.fluid,
            naca_code=naca_code,
            chord_length=chord_length,
            center_x=center_x,
            center_y=center_y,
        )

    def step(self, steps=1):
        cur_SEC.cur_sec["OverRelax"] = self.over_relax

        for _ in range(steps):
            self.apply_inlet()
            self.fluid.integrate_g(self.dt, self.gravity)
            self.fluid.p.fill(0.0)
            self.fluid.incompressibility_solve(self.iterations, self.dt)
            self.fluid.Extrapolate()
            self.fluid.advection_vel(self.dt)
            self.fluid.advection_smoke(self.dt)
            self.apply_inlet()

    def speed_field(self):
        n = self.fluid.numY
        speed = np.zeros((self.grid_h, self.grid_w), dtype=np.float32)

        for i in range(1, self.fluid.numX - 1):
            for j in range(1, self.fluid.numY - 1):
                idx = i * n + j
                u = 0.5 * (self.fluid.u[idx] + self.fluid.u[(i + 1) * n + j])
                v = 0.5 * (self.fluid.v[idx] + self.fluid.v[i * n + (j + 1)])
                speed[j - 1, i - 1] = np.sqrt(u * u + v * v)

        return speed

    def smoke_field(self):
        smoke = np.zeros((self.grid_h, self.grid_w), dtype=np.float32)

        for i in range(1, self.fluid.numX - 1):
            for j in range(1, self.fluid.numY - 1):
                smoke[j - 1, i - 1] = self.fluid.m[self._idx(i, j)]

        return smoke

    def pressure_field(self):
        pressure = np.zeros((self.grid_h, self.grid_w), dtype=np.float32)

        for i in range(1, self.fluid.numX - 1):
            for j in range(1, self.fluid.numY - 1):
                pressure[j - 1, i - 1] = self.fluid.p[self._idx(i, j)]

        return pressure

    def solid_field(self):
        solid = np.zeros((self.grid_h, self.grid_w), dtype=np.float32)

        for i in range(1, self.fluid.numX - 1):
            for j in range(1, self.fluid.numY - 1):
                solid[j - 1, i - 1] = 1.0 - self.fluid.s[self._idx(i, j)]

        return solid

    def export_cell_data(self):
        n = self.fluid.numY
        rows = []

        for i in range(1, self.fluid.numX - 1):
            for j in range(1, self.fluid.numY - 1):
                idx = i * n + j
                u_center = 0.5 * (self.fluid.u[idx] + self.fluid.u[(i + 1) * n + j])
                v_center = 0.5 * (self.fluid.v[idx] + self.fluid.v[i * n + (j + 1)])
                rows.append(
                    (
                        idx,
                        i,
                        j,
                        self.fluid.s[idx],
                        self.fluid.u[idx],
                        self.fluid.v[idx],
                        u_center,
                        v_center,
                        float(np.sqrt(u_center * u_center + v_center * v_center)),
                        self.fluid.m[idx],
                        self.fluid.p[idx],
                    )
                )

        return np.array(
            rows,
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


def save_cell_csv(path, cell_data):
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


def save_field_plot(path, speed, smoke, pressure, solid):
    fig, axes = plt.subplots(2, 2, figsize=(12, 8), constrained_layout=True)
    plots = [
        (smoke, "Smoke", "gray"),
        (speed, "Speed Magnitude", "viridis"),
        (pressure, "Pressure", "coolwarm"),
        (solid, "Solid Mask", "binary"),
    ]

    for ax, (field, title, cmap) in zip(axes.ravel(), plots):
        image = ax.imshow(field, origin="lower", cmap=cmap, aspect="auto")
        ax.set_title(title)
        ax.set_xlabel("i")
        ax.set_ylabel("j")
        fig.colorbar(image, ax=ax, shrink=0.85)

    fig.suptitle("Airfoil Flow Report")
    fig.savefig(path, dpi=180)
    plt.close(fig)


def build_parser():
    parser = argparse.ArgumentParser(
        description="Run the airfoil simulation and export only the final-state results."
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
    parser.add_argument("--naca-code", default="2412")
    parser.add_argument("--chord-length", type=float, default=30.0)
    parser.add_argument("--center", nargs=2, type=float, metavar=("X", "Y"), default=(70.0, 51.0))
    parser.add_argument("--output-dir", default="outputs")
    return parser


def main():
    args = build_parser().parse_args()

    grid_w, grid_h = args.resolution
    center_x, center_y = args.center

    sim = HeadlessWindTunnel(
        grid_w=grid_w,
        grid_h=grid_h,
        iterations=args.iterations,
        dt=args.dt,
        flow_speed=args.flow_speed,
        smoke_strength=args.smoke_strength,
        gravity=args.gravity,
        over_relax=args.over_relax,
        inlet_columns=args.inlet_columns,
    )
    sim.set_obstacle_airfoil(
        args.naca_code,
        chord_length=args.chord_length,
        center_x=center_x,
        center_y=center_y,
    )

    output_dir = Path(args.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    max_steps = args.hardstep
    min_steps = args.min_steps
    steady_tol = args.steady_tol
    previous_speed = None
    residual_history = []

    start = time.perf_counter()
    steps_run = max_steps

    for step in range(1, max_steps + 1):
        sim.step(1)
        speed = sim.speed_field()

        if previous_speed is not None:
            residual = float(np.max(np.abs(speed - previous_speed)))
            residual_history.append((step, residual))
            if step == 2 or step % 10 == 0:
                print(
                    f"step {step}/{max_steps} | max_speed_change={residual:.6e}",
                    flush=True,
                )
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
        print(
            f"max steps reached without meeting steady tolerance {steady_tol:.1e}",
            flush=True,
        )

    elapsed = time.perf_counter() - start

    speed = sim.speed_field()
    smoke = sim.smoke_field()
    pressure = sim.pressure_field()
    solid = sim.solid_field()
    cell_data = sim.export_cell_data()

    save_cell_csv(output_dir / "airfoil_cells.csv", cell_data)
    save_field_plot(output_dir / "airfoil_fields.png", speed, smoke, pressure, solid)

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
