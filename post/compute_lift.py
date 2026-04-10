#!/usr/bin/env python3

import argparse
import csv
from dataclasses import dataclass
from pathlib import Path


@dataclass
class Cell:
    i: int
    j: int
    solid_flag: float
    pressure: float

    @property
    def is_fluid(self) -> bool:
        return self.solid_flag != 0.0

    @property
    def is_solid(self) -> bool:
        return self.solid_flag == 0.0


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Read a fluid-solver CSV dump and compute lift from pressure "
            "on the fluid-solid interfaces."
        )
    )
    parser.add_argument(
        "csv_file",
        nargs="?",
        default="airfoil_cells.csv",
        help="Path to the CSV file exported by the solver.",
    )
    parser.add_argument(
        "--dx",
        type=float,
        default=0.001,
        help="Cell width in the x direction in meters. Default: 0.001 (1 mm)",
    )
    parser.add_argument(
        "--dy",
        type=float,
        default=0.001,
        help="Cell height in the y direction in meters. Default: 0.001 (1 mm)",
    )
    parser.add_argument(
        "--p-ref",
        type=float,
        default=None,
        help=(
            "Reference pressure to subtract before integrating. "
            "If omitted, the script estimates it from the outer fluid boundary."
        ),
    )
    parser.add_argument(
        "--rho",
        type=float,
        default=None,
        help="Fluid density. Provide with --u-inf and --chord to also compute Cl.",
    )
    parser.add_argument(
        "--u-inf",
        type=float,
        default=None,
        help="Freestream speed. Provide with --rho and --chord to also compute Cl.",
    )
    parser.add_argument(
        "--chord",
        type=float,
        default=None,
        help="Airfoil chord length. Provide with --rho and --u-inf to also compute Cl.",
    )
    parser.add_argument(
        "--span",
        type=float,
        default=1.0,
        help=(
            "Out-of-plane span/depth used to convert face length into area. "
            "Default: 1.0 m"
        ),
    )
    parser.add_argument(
        "--unit-system",
        choices=("si", "solver"),
        default="si",
        help=(
            "Output labels to use. 'si' assumes the solver inputs follow SI units "
            "(kg, m, s, Pa). 'solver' keeps generic solver-native labels. Default: si"
        ),
    )
    return parser.parse_args()


def load_cells(csv_path: Path) -> dict[tuple[int, int], Cell]:
    cells: dict[tuple[int, int], Cell] = {}
    with csv_path.open(newline="") as handle:
        reader = csv.DictReader(handle)
        required = {"i", "j", "s", "pressure"}
        missing = required.difference(reader.fieldnames or [])
        if missing:
            raise ValueError(f"CSV is missing required columns: {sorted(missing)}")

        for row in reader:
            i = int(float(row["i"]))
            j = int(float(row["j"]))
            cells[(i, j)] = Cell(
                i=i,
                j=j,
                solid_flag=float(row["s"]),
                pressure=float(row["pressure"]),
            )
    if not cells:
        raise ValueError("CSV contains no data rows.")
    return cells


def estimate_reference_pressure(cells: dict[tuple[int, int], Cell]) -> float:
    fluid_pressures = []
    max_i = max(i for i, _ in cells)
    max_j = max(j for _, j in cells)

    for (i, j), cell in cells.items():
        if not cell.is_fluid:
            continue
        if i in (1, max_i) or j in (1, max_j):
            fluid_pressures.append(cell.pressure)

    if not fluid_pressures:
        return 0.0
    return sum(fluid_pressures) / len(fluid_pressures)


def compute_pressure_forces(
    cells: dict[tuple[int, int], Cell], dx: float, dy: float, span: float, p_ref: float
) -> tuple[float, float, int]:
    force_x = 0.0
    force_y = 0.0
    interface_count = 0

    neighbor_offsets = (
        (1, 0, dy * span),
        (-1, 0, dy * span),
        (0, 1, dx * span),
        (0, -1, dx * span),
    )

    for (i, j), solid in cells.items():
        if not solid.is_solid:
            continue

        for di, dj, area in neighbor_offsets:
            fluid = cells.get((i + di, j + dj))
            if fluid is None or not fluid.is_fluid:
                continue

            pressure = fluid.pressure - p_ref
            force_x += -pressure * di * area
            force_y += -pressure * dj * area
            interface_count += 1

    return force_x, force_y, interface_count


def compute_cl(lift: float, rho: float, u_inf: float, chord: float) -> float:
    q_inf = 0.5 * rho * u_inf * u_inf
    if q_inf == 0.0 or chord == 0.0:
        raise ValueError("Dynamic pressure and chord must be non-zero to compute Cl.")
    return lift / (q_inf * chord)


def unit_labels(unit_system: str) -> dict[str, str]:
    if unit_system == "si":
        return {
            "pressure": "Pa",
            "length": "m",
            "area": "m^2",
            "force": "N",
            "density": "kg/m^3",
            "velocity": "m/s",
            "time": "s",
            "gravity": "m/s^2",
        }
    return {
        "pressure": "solver pressure units",
        "length": "solver length units",
        "area": "solver length units^2",
        "force": "solver pressure units * solver length units^2",
        "density": "solver density units",
        "velocity": "solver velocity units",
        "time": "solver time units",
        "gravity": "solver acceleration units",
    }


def main() -> None:
    args = parse_args()
    csv_path = Path(args.csv_file)
    cells = load_cells(csv_path)

    p_ref = args.p_ref
    if p_ref is None:
        p_ref = estimate_reference_pressure(cells)

    drag, lift, interfaces = compute_pressure_forces(
        cells, args.dx, args.dy, args.span, p_ref
    )
    units = unit_labels(args.unit_system)

    print()
    print("Lift Report")
    print("=" * 40)
    print(f"CSV file                  : {csv_path}")
    print(f"Cells loaded              : {len(cells)}")
    print(f"Fluid-solid interfaces    : {interfaces}")
    print(f"Reference pressure        : {p_ref:12.6f} {units['pressure']}")
    print()
    print("Geometry Assumptions")
    print("-" * 40)
    print(f"dx                        : {args.dx:12.6f} {units['length']}")
    print(f"dy                        : {args.dy:12.6f} {units['length']}")
    print(f"span/depth                : {args.span:12.6f} {units['length']}")
    print(f"Face area units           : {units['area']}")
    print()
    print("Integrated Pressure Forces")
    print("-" * 40)
    print(f"Drag (x)                  : {drag:12.6f} {units['force']}")
    print(f"Lift (y)                  : {lift:12.6f} {units['force']}")
    print()
    print("Recommended Units From Solver")
    print("-" * 40)
    print("The pressure update uses cp = density * h / dt, so the code is dimensionally")
    print("consistent with SI inputs:")
    print(f"  density   : {units['density']}")
    print(f"  h, dx, dy : {units['length']}")
    print(f"  dt        : {units['time']}")
    print(f"  u, v      : {units['velocity']}")
    print(f"  gravity   : {units['gravity']}")
    print(f"  pressure  : {units['pressure']}")
    print()
    if args.unit_system == "si":
        print("With those choices, the integrated force is reported in N.")
    else:
        print("Force remains in solver-native units until you map the solver inputs to a")
        print("physical unit system.")

    if args.rho is not None and args.u_inf is not None and args.chord is not None:
        cl = compute_cl(lift, args.rho, args.u_inf, args.chord)
        print()
        print("Aerodynamic Coefficient")
        print("-" * 40)
        print(f"Lift coefficient Cl       : {cl:12.6f}")


if __name__ == "__main__":
    main()
