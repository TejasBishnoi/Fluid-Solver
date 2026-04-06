import argparse
from pathlib import Path

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np

from visualizer import wt

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


def plot_fields(output_path, speed, smoke, pressure, solid):
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
    fig.savefig(output_path, dpi=180)
    plt.close(fig)


def run_case(args):
    sim = wt(
        grid_w=args.grid_w,
        grid_h=args.grid_h,
        density=args.density,
        flow_speed=args.flow_speed,
        smoke_strength=args.smoke_strength,
        gravity=args.gravity,
        dt=args.dt,
        iterations=args.iterations,
        over_relax=args.over_relax,
        inlet_columns=args.inlet_columns,
    )

    sim.set_obstacle_airfoil(
        naca_code=args.naca_code,
        chord_length=args.chord_length,
        center_x=args.center_x,
        center_y=args.center_y,
    )

    previous_speed = None
    residual_history = []

    for step in range(1, args.steps + 1):
        sim.step(1)
        speed = sim.speed_field()

        if previous_speed is not None:
            residual = float(np.max(np.abs(speed - previous_speed)))
            residual_history.append((step, residual))
            if residual < args.steady_tol and step >= args.min_steps:
                break

        previous_speed = speed.copy()

    cell_data = sim.export_cell_data()
    speed = sim.speed_field()
    smoke = sim.smoke_field()
    pressure = sim.pressure_field()
    solid = sim.solid_field()

    return {
        "steps_run": step,
        "residual_history": residual_history,
        "cell_data": cell_data,
        "speed": speed,
        "smoke": smoke,
        "pressure": pressure,
        "solid": solid,
    }


def build_parser():
    parser = argparse.ArgumentParser(description="Run an airfoil CFD case and export plots plus per-cell CSV data.")
    parser.add_argument("--grid-w", type=int, default=200)
    parser.add_argument("--grid-h", type=int, default=100)
    parser.add_argument("--density", type=float, default=1.0)
    parser.add_argument("--flow-speed", type=float, default=9.0)
    parser.add_argument("--smoke-strength", type=float, default=1.0)
    parser.add_argument("--gravity", type=float, default=0.0)
    parser.add_argument("--dt", type=float, default=0.08)
    parser.add_argument("--iterations", type=int, default=30)
    parser.add_argument("--over-relax", type=float, default=1.9)
    parser.add_argument("--inlet-columns", type=int, default=3)
    parser.add_argument("--naca-code", default="2412")
    parser.add_argument("--chord-length", type=float, default=30.0)
    parser.add_argument("--center-x", type=float, default=70.0)
    parser.add_argument("--center-y", type=float, default=51.0)
    parser.add_argument("--steps", type=int, default=400)
    parser.add_argument("--min-steps", type=int, default=100)
    parser.add_argument("--steady-tol", type=float, default=1e-4)
    parser.add_argument("--output-dir", default="outputs")
    return parser


def main():
    parser = build_parser()
    args = parser.parse_args()

    output_dir = Path(args.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    result = run_case(args)

    csv_path = output_dir / "airfoil_cells.csv"
    plot_path = output_dir / "airfoil_fields.png"
    residual_path = output_dir / "residual_history.csv"

    save_cell_csv(csv_path, result["cell_data"])
    plot_fields(plot_path, result["speed"], result["smoke"], result["pressure"], result["solid"])

    if result["residual_history"]:
        residual_data = np.array(result["residual_history"], dtype=np.float64)
        np.savetxt(
            residual_path,
            residual_data,
            delimiter=",",
            header="step,max_speed_change",
            comments="",
            fmt="%.6f",
        )

    print(f"steps_run: {result['steps_run']}")
    print(f"csv: {csv_path}")
    print(f"plot: {plot_path}")
    if result["residual_history"]:
        print(f"residual_csv: {residual_path}")
        print(f"final_residual: {result['residual_history'][-1][1]:.6e}")
    print(f"max_speed: {float(np.max(result['speed'])):.6f}")
    print(f"max_pressure: {float(np.max(result['pressure'])):.6f}")
    print(f"min_pressure: {float(np.min(result['pressure'])):.6f}")


if __name__ == "__main__":
    main()
