import numpy as np


def point_in_polygon(x, y, polygon):
    """Return True when point (x, y) lies inside a closed polygon."""
    inside = False
    count = len(polygon)

    if count < 3:
        return False

    for idx in range(count):
        x1, y1 = polygon[idx]
        x2, y2 = polygon[(idx + 1) % count]

        if ((y1 > y) != (y2 > y)):
            denom = y2 - y1
            if denom == 0.0:
                continue
            x_intersection = (x2 - x1) * (y - y1) / denom + x1
            if x < x_intersection:
                inside = not inside

    return inside


def generate_naca4_coordinates(naca_code, num_points=200):
    """
    Generate a closed polygon for a NACA 4-digit airfoil in unit-chord space.

    The returned coordinates span x in [0, 1] with the airfoil centered
    vertically around y = 0.
    """
    if len(naca_code) != 4 or not naca_code.isdigit():
        raise ValueError("naca_code must be a 4-digit string such as '0012' or '2412'")

    m = int(naca_code[0]) / 100.0
    p = int(naca_code[1]) / 10.0
    t = int(naca_code[2:]) / 100.0

    beta = np.linspace(0.0, np.pi, num_points)
    x = 0.5 * (1.0 - np.cos(beta))

    yt = 5.0 * t * (
        0.2969 * np.sqrt(x)
        - 0.1260 * x
        - 0.3516 * x**2
        + 0.2843 * x**3
        - 0.1015 * x**4
    )

    yc = np.zeros_like(x)
    dyc_dx = np.zeros_like(x)

    if m > 0.0 and p > 0.0:
        leading = x < p
        trailing = ~leading

        yc[leading] = m / (p**2) * (2.0 * p * x[leading] - x[leading] ** 2)
        yc[trailing] = m / ((1.0 - p) ** 2) * (
            (1.0 - 2.0 * p) + 2.0 * p * x[trailing] - x[trailing] ** 2
        )

        dyc_dx[leading] = 2.0 * m / (p**2) * (p - x[leading])
        dyc_dx[trailing] = 2.0 * m / ((1.0 - p) ** 2) * (p - x[trailing])

    theta = np.arctan(dyc_dx)

    xu = x - yt * np.sin(theta)
    yu = yc + yt * np.cos(theta)
    xl = x + yt * np.sin(theta)
    yl = yc - yt * np.cos(theta)

    upper = np.column_stack((xu[::-1], yu[::-1]))
    lower = np.column_stack((xl[1:], yl[1:]))
    polygon = np.vstack((upper, lower))

    return polygon


def apply_naca_airfoil(fluid, naca_code, chord_length, center_x, center_y):
    """
    Rasterize a NACA 4-digit airfoil into the structured CFD grid.

    Cells inside the airfoil are marked solid and their velocity/smoke values
    are zeroed. Inlet cells with i <= 3 are preserved.
    """
    if chord_length <= 0.0:
        raise ValueError("chord_length must be positive")

    unit_polygon = generate_naca4_coordinates(naca_code)

    x_offset = center_x - 0.5 * chord_length
    y_offset = center_y

    polygon = np.empty_like(unit_polygon)
    polygon[:, 0] = x_offset + unit_polygon[:, 0] * chord_length
    polygon[:, 1] = y_offset + unit_polygon[:, 1] * chord_length

    min_x = max(4, int(np.floor(np.min(polygon[:, 0]))))
    max_x = min(fluid.numX - 2, int(np.ceil(np.max(polygon[:, 0]))))
    min_y = max(1, int(np.floor(np.min(polygon[:, 1]))))
    max_y = min(fluid.numY - 2, int(np.ceil(np.max(polygon[:, 1]))))

    if min_x > max_x or min_y > max_y:
        return polygon

    idx_fn = getattr(fluid, "_idx", None)

    for i in range(min_x, max_x + 1):
        if i <= 3:
            continue
        for j in range(min_y, max_y + 1):
            if point_in_polygon(i, j, polygon):
                if idx_fn is not None:
                    idx = idx_fn(i, j)
                else:
                    idx = i * fluid.numY + j
                fluid.s[idx] = 0.0
                fluid.u[idx] = 0.0
                fluid.v[idx] = 0.0
                fluid.m[idx] = 0.0

    return polygon
