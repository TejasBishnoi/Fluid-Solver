from __future__ import annotations

from enum import IntEnum
from typing import Any

import numpy as np
import numpy.typing as npt

try:
    import taichi as ti
except ImportError:
    ti = None


FloatArray = npt.NDArray[np.float32]
OVER_RELAXATION: float = 1.9
_TAICHI_INITIALIZED = False


def set_over_relaxation(value: float) -> None:
    global OVER_RELAXATION
    OVER_RELAXATION = value


class FIELDS(IntEnum):
    U_field = 1
    V_field = 2
    S_field = 3


def _clamp_scalar(val: float, min_val: float, max_val: float) -> float:
    if not np.isfinite(val):
        return min_val
    return max(min(val, max_val), min_val)


class _NumpyFluid:
    def __init__(self, density: float, numX: int, numY: int, h: float) -> None:
        self.density = density
        self.numX = numX + 2
        self.numY = numY + 2
        self.h = h
        self.numCells = self.numX * self.numY
        self.u: FloatArray = np.zeros(self.numCells, dtype=np.float32)
        self.v: FloatArray = np.zeros(self.numCells, dtype=np.float32)
        self.nU: FloatArray = np.zeros(self.numCells, dtype=np.float32)
        self.nV: FloatArray = np.zeros(self.numCells, dtype=np.float32)
        self.p: FloatArray = np.zeros(self.numCells, dtype=np.float32)
        self.s: FloatArray = np.zeros(self.numCells, dtype=np.float32)
        self.m: FloatArray = np.zeros(self.numCells, dtype=np.float32)
        self.nM: FloatArray = np.ones(self.numCells, dtype=np.float32)
        i_idx = np.arange(1, self.numX - 1, dtype=np.int32)[:, None]
        j_idx = np.arange(1, self.numY - 1, dtype=np.int32)[None, :]
        self._red_mask = ((i_idx + j_idx) & 1) == 0
        self._black_mask = ~self._red_mask

    def _reshape_field(self, field: FloatArray) -> npt.NDArray[np.float32]:
        return field.reshape(self.numX, self.numY)

    def clamp(self, val: float, min_val: float, max_val: float) -> float:
        return _clamp_scalar(val, min_val, max_val)

    def integrate_g(self, dt: float, gravity: float) -> None:
        s = self._reshape_field(self.s)
        v = self._reshape_field(self.v)
        mask = (s[1:, 1:-1] != 0.0) & (s[:-1, 1:-1] != 0.0)
        v_slice = v[1:, 1:-1]
        v_slice[mask] += np.float32(gravity * dt)

    def incompressibility_solve(self, itt: int, dt: float) -> None:
        u = self._reshape_field(self.u)
        v = self._reshape_field(self.v)
        p = self._reshape_field(self.p)
        s = self._reshape_field(self.s)

        center_s = s[1:-1, 1:-1]
        sx0 = s[:-2, 1:-1]
        sx1 = s[2:, 1:-1]
        sy0 = s[1:-1, :-2]
        sy1 = s[1:-1, 2:]
        solid_sum = sx0 + sx1 + sy0 + sy1
        fluid_mask = center_s != 0.0
        solvable_mask = fluid_mask & (solid_sum != 0.0)

        cp = np.float32(self.density * self.h / dt)
        over_relax = np.float32(OVER_RELAXATION)
        pressure_delta = np.zeros_like(center_s)

        for _ in range(itt):
            for color_mask in (self._red_mask, self._black_mask):
                divergence = (u[2:, 1:-1] - u[1:-1, 1:-1]) + (v[1:-1, 2:] - v[1:-1, 1:-1])
                active = solvable_mask & color_mask
                np.divide(-divergence, solid_sum, out=pressure_delta, where=active)
                pressure_delta *= over_relax
                pressure_delta[~active] = 0.0
                p[1:-1, 1:-1] += cp * pressure_delta
                u[1:-1, 1:-1] -= sx0 * pressure_delta
                u[2:, 1:-1] += sx1 * pressure_delta
                v[1:-1, 1:-1] -= sy0 * pressure_delta
                v[1:-1, 2:] += sy1 * pressure_delta

    def Extrapolate(self) -> None:
        u = self._reshape_field(self.u)
        v = self._reshape_field(self.v)
        u[:, 0] = u[:, 1]
        u[:, -1] = u[:, -2]
        v[0, :] = v[1, :]
        v[-1, :] = v[-2, :]

    def sampleFields(self, x: float, y: float, field: FIELDS) -> np.float32:
        n = self.numY
        h = self.h
        h1 = 1.0 / h
        h2 = 0.5 * h

        x = self.clamp(x, h, self.numX * h)
        y = self.clamp(y, h, self.numY * h)

        dx = 0.0
        dy = 0.0
        field_data: FloatArray = self.m

        if field == FIELDS.U_field:
            field_data = self.u
            dy = h2
        elif field == FIELDS.V_field:
            field_data = self.v
            dx = h2
        else:
            field_data = self.m
            dx = h2
            dy = h2

        x0 = min(int((x - dx) * h1), self.numX - 1)
        tx = ((x - dx) - x0 * h) * h1
        x1 = min(x0 + 1, self.numX - 1)

        y0 = min(int((y - dy) * h1), self.numY - 1)
        ty = ((y - dy) - y0 * h) * h1
        y1 = min(y0 + 1, self.numY - 1)

        sx = 1.0 - tx
        sy = 1.0 - ty
        return np.float32(
            sx * sy * field_data[x0 * n + y0]
            + tx * sy * field_data[x1 * n + y0]
            + tx * ty * field_data[x1 * n + y1]
            + sx * ty * field_data[x0 * n + y1]
        )

    def avg_U(self, i: int, j: int) -> np.float32:
        n = self.numY
        return np.float32(
            (
                self.u[i * n + j - 1]
                + self.u[i * n + j]
                + self.u[(i + 1) * n + j - 1]
                + self.u[(i + 1) * n + j]
            )
            * 0.25
        )

    def avg_V(self, i: int, j: int) -> np.float32:
        n = self.numY
        return np.float32(
            (
                self.v[(i - 1) * n + j]
                + self.v[i * n + j]
                + self.v[(i - 1) * n + j + 1]
                + self.v[i * n + j + 1]
            )
            * 0.25
        )

    def advection_vel(self, dt: float) -> None:
        self.nU[:] = self.u
        self.nV[:] = self.v

        n = self.numY
        h = self.h
        h2 = 0.5 * h

        for i in range(1, self.numX):
            for j in range(1, self.numY):
                if self.s[i * n + j] != 0.0 and self.s[(i - 1) * n + j] != 0.0 and j < self.numY - 1:
                    x = i * h
                    y = j * h + h2
                    u_val = float(self.u[i * n + j])
                    v_val = float(self.avg_V(i, j))
                    x -= dt * u_val
                    y -= dt * v_val
                    if not np.isfinite(x):
                        x = i * h
                    if not np.isfinite(y):
                        y = j * h + h2
                    self.nU[i * n + j] = self.sampleFields(x, y, FIELDS.U_field)

                if self.s[i * n + j] != 0.0 and self.s[i * n + j - 1] != 0.0 and i < self.numX - 1:
                    x = i * h + h2
                    y = j * h
                    u_val = float(self.avg_U(i, j))
                    v_val = float(self.v[i * n + j])
                    x -= dt * u_val
                    y -= dt * v_val
                    if not np.isfinite(x):
                        x = i * h + h2
                    if not np.isfinite(y):
                        y = j * h
                    self.nV[i * n + j] = self.sampleFields(x, y, FIELDS.V_field)

        self.u[:] = self.nU
        self.v[:] = self.nV

    def advection_smoke(self, dt: float) -> None:
        self.nM[:] = self.m
        n = self.numY
        h = self.h
        h2 = 0.5 * h

        for i in range(1, self.numX - 1):
            for j in range(1, self.numY - 1):
                idx = i * n + j
                if self.s[idx] != 0.0:
                    u_val = float((self.u[idx] + self.u[(i + 1) * n + j]) * 0.25)
                    v_val = float((self.v[idx] + self.v[i * n + j + 1]) * 0.5)
                    x = i * h + h2 - dt * u_val
                    y = j * h + h2 - dt * v_val
                    self.nM[idx] = self.sampleFields(x, y, FIELDS.S_field)
                else:
                    self.nM[idx] = 0.0

        self.m[:] = self.nM


if ti is not None:
    class _TaichiArrayProxy:
        def __init__(self, field: Any) -> None:
            self._field = field

        def __getitem__(self, key: Any) -> Any:
            if isinstance(key, slice):
                return self._field.to_numpy()[key]
            return np.float32(self._field[key])

        def __setitem__(self, key: Any, value: Any) -> None:
            if isinstance(key, slice):
                if key != slice(None, None, None):
                    raise NotImplementedError("Only full-slice assignment is supported.")
                if isinstance(value, _TaichiArrayProxy):
                    self._field.copy_from(value._field)
                    return
                np_value = np.asarray(value, dtype=np.float32)
                if np_value.shape != (self._field.shape[0],):
                    raise ValueError("Slice assignment requires a full-length 1D array.")
                self._field.from_numpy(np_value)
                return
            self._field[key] = np.float32(value)

        def fill(self, value: float) -> None:
            self._field.fill(np.float32(value))

        def to_numpy(self) -> FloatArray:
            return self._field.to_numpy()

        def __array__(self, dtype: Any = None) -> np.ndarray[Any, Any]:
            array = self._field.to_numpy()
            if dtype is not None:
                return array.astype(dtype)
            return array


    @ti.data_oriented
    class _TaichiFluid:
        def __init__(self, density: float, numX: int, numY: int, h: float) -> None:
            global _TAICHI_INITIALIZED

            if not _TAICHI_INITIALIZED:
                ti.init(arch=ti.cpu, default_fp=ti.f32)
                _TAICHI_INITIALIZED = True

            self.density = np.float32(density)
            self.numX = numX + 2
            self.numY = numY + 2
            self.h = np.float32(h)
            self.numCells = self.numX * self.numY

            self._u = ti.field(dtype=ti.f32, shape=self.numCells)
            self._v = ti.field(dtype=ti.f32, shape=self.numCells)
            self._nU = ti.field(dtype=ti.f32, shape=self.numCells)
            self._nV = ti.field(dtype=ti.f32, shape=self.numCells)
            self._p = ti.field(dtype=ti.f32, shape=self.numCells)
            self._s = ti.field(dtype=ti.f32, shape=self.numCells)
            self._m = ti.field(dtype=ti.f32, shape=self.numCells)
            self._nM = ti.field(dtype=ti.f32, shape=self.numCells)

            self.u = _TaichiArrayProxy(self._u)
            self.v = _TaichiArrayProxy(self._v)
            self.nU = _TaichiArrayProxy(self._nU)
            self.nV = _TaichiArrayProxy(self._nV)
            self.p = _TaichiArrayProxy(self._p)
            self.s = _TaichiArrayProxy(self._s)
            self.m = _TaichiArrayProxy(self._m)
            self.nM = _TaichiArrayProxy(self._nM)

            self._zero_buffers()
            self._nM.fill(1.0)

        def clamp(self, val: float, min_val: float, max_val: float) -> float:
            return _clamp_scalar(val, min_val, max_val)

        @ti.kernel
        def _zero_buffers(self) -> None:
            for idx in range(self.numCells):
                self._u[idx] = 0.0
                self._v[idx] = 0.0
                self._nU[idx] = 0.0
                self._nV[idx] = 0.0
                self._p[idx] = 0.0
                self._s[idx] = 0.0
                self._m[idx] = 0.0

        @ti.func
        def _sample_field_ti(self, x: ti.f32, y: ti.f32, field: ti.i32) -> ti.f32:
            h = self.h
            h1 = 1.0 / h
            h2 = 0.5 * h

            x = ti.max(h, ti.min(x, self.numX * h))
            y = ti.max(h, ti.min(y, self.numY * h))

            dx = 0.0
            dy = 0.0
            if field == int(FIELDS.U_field):
                dy = h2
            elif field == int(FIELDS.V_field):
                dx = h2
            else:
                dx = h2
                dy = h2

            x0 = ti.min(int((x - dx) * h1), self.numX - 1)
            tx = ((x - dx) - x0 * h) * h1
            x1 = ti.min(x0 + 1, self.numX - 1)

            y0 = ti.min(int((y - dy) * h1), self.numY - 1)
            ty = ((y - dy) - y0 * h) * h1
            y1 = ti.min(y0 + 1, self.numY - 1)

            n = self.numY

            v00 = 0.0
            v10 = 0.0
            v11 = 0.0
            v01 = 0.0
            if field == int(FIELDS.U_field):
                v00 = self._u[x0 * n + y0]
                v10 = self._u[x1 * n + y0]
                v11 = self._u[x1 * n + y1]
                v01 = self._u[x0 * n + y1]
            elif field == int(FIELDS.V_field):
                v00 = self._v[x0 * n + y0]
                v10 = self._v[x1 * n + y0]
                v11 = self._v[x1 * n + y1]
                v01 = self._v[x0 * n + y1]
            else:
                v00 = self._m[x0 * n + y0]
                v10 = self._m[x1 * n + y0]
                v11 = self._m[x1 * n + y1]
                v01 = self._m[x0 * n + y1]

            sx = 1.0 - tx
            sy = 1.0 - ty
            return sx * sy * v00 + tx * sy * v10 + tx * ty * v11 + sx * ty * v01

        @ti.func
        def _avg_u_ti(self, i: ti.i32, j: ti.i32) -> ti.f32:
            n = self.numY
            return (
                self._u[i * n + j - 1]
                + self._u[i * n + j]
                + self._u[(i + 1) * n + j - 1]
                + self._u[(i + 1) * n + j]
            ) * 0.25

        @ti.func
        def _avg_v_ti(self, i: ti.i32, j: ti.i32) -> ti.f32:
            n = self.numY
            return (
                self._v[(i - 1) * n + j]
                + self._v[i * n + j]
                + self._v[(i - 1) * n + j + 1]
                + self._v[i * n + j + 1]
            ) * 0.25

        @ti.kernel
        def _integrate_g(self, dt: ti.f32, gravity: ti.f32) -> None:
            n = self.numY
            for i, j in ti.ndrange((1, self.numX), (1, self.numY - 1)):
                idx = i * n + j
                if self._s[idx] != 0.0 and self._s[idx - 1] != 0.0:
                    self._v[idx] += gravity * dt

        def integrate_g(self, dt: float, gravity: float) -> None:
            self._integrate_g(np.float32(dt), np.float32(gravity))

        @ti.kernel
        def _incompressibility_iteration(self, cp: ti.f32, over_relaxation: ti.f32) -> None:
            n = self.numY
            for i, j in ti.ndrange((1, self.numX - 1), (1, self.numY - 1)):
                idx = i * n + j
                if self._s[idx] != 0.0:
                    sx0 = self._s[(i - 1) * n + j]
                    sx1 = self._s[(i + 1) * n + j]
                    sy0 = self._s[i * n + (j - 1)]
                    sy1 = self._s[i * n + (j + 1)]
                    solid_sum = sx0 + sx1 + sy0 + sy1

                    if solid_sum != 0.0:
                        divergence = (
                            self._u[(i + 1) * n + j]
                            - self._u[idx]
                            + self._v[i * n + (j + 1)]
                            - self._v[idx]
                        )
                        pressure_delta = (-divergence / solid_sum) * over_relaxation
                        self._p[idx] += cp * pressure_delta
                        self._u[idx] -= sx0 * pressure_delta
                        self._u[(i + 1) * n + j] += sx1 * pressure_delta
                        self._v[idx] -= sy0 * pressure_delta
                        self._v[i * n + (j + 1)] += sy1 * pressure_delta

        def incompressibility_solve(self, itt: int, dt: float) -> None:
            cp = np.float32(self.density * self.h / dt)
            for _ in range(itt):
                self._incompressibility_iteration(cp, np.float32(OVER_RELAXATION))

        @ti.kernel
        def _extrapolate(self) -> None:
            n = self.numY
            for i in range(self.numX):
                self._u[i * n] = self._u[i * n + 1]
                self._u[i * n + self.numY - 1] = self._u[i * n + self.numY - 2]

            for j in range(self.numY):
                self._v[j] = self._v[n + j]
                self._v[(self.numX - 1) * n + j] = self._v[(self.numX - 2) * n + j]

        def Extrapolate(self) -> None:
            self._extrapolate()

        def sampleFields(self, x: float, y: float, field: FIELDS) -> np.float32:
            n = self.numY
            h = self.h
            h1 = 1.0 / h
            h2 = 0.5 * h

            x = self.clamp(x, h, self.numX * h)
            y = self.clamp(y, h, self.numY * h)

            dx = 0.0
            dy = 0.0
            field_data = self.m

            if field == FIELDS.U_field:
                field_data = self.u
                dy = h2
            elif field == FIELDS.V_field:
                field_data = self.v
                dx = h2
            else:
                field_data = self.m
                dx = h2
                dy = h2

            x0 = min(int((x - dx) * h1), self.numX - 1)
            tx = ((x - dx) - x0 * h) * h1
            x1 = min(x0 + 1, self.numX - 1)

            y0 = min(int((y - dy) * h1), self.numY - 1)
            ty = ((y - dy) - y0 * h) * h1
            y1 = min(y0 + 1, self.numY - 1)

            sx = 1.0 - tx
            sy = 1.0 - ty
            return np.float32(
                sx * sy * field_data[x0 * n + y0]
                + tx * sy * field_data[x1 * n + y0]
                + tx * ty * field_data[x1 * n + y1]
                + sx * ty * field_data[x0 * n + y1]
            )

        def avg_U(self, i: int, j: int) -> np.float32:
            n = self.numY
            return np.float32(
                (
                    self.u[i * n + j - 1]
                    + self.u[i * n + j]
                    + self.u[(i + 1) * n + j - 1]
                    + self.u[(i + 1) * n + j]
                )
                * 0.25
            )

        def avg_V(self, i: int, j: int) -> np.float32:
            n = self.numY
            return np.float32(
                (
                    self.v[(i - 1) * n + j]
                    + self.v[i * n + j]
                    + self.v[(i - 1) * n + j + 1]
                    + self.v[i * n + j + 1]
                )
                * 0.25
            )

        @ti.kernel
        def _copy_velocity_buffers(self) -> None:
            for idx in range(self.numCells):
                self._nU[idx] = self._u[idx]
                self._nV[idx] = self._v[idx]

        @ti.kernel
        def _copy_velocity_back(self) -> None:
            for idx in range(self.numCells):
                self._u[idx] = self._nU[idx]
                self._v[idx] = self._nV[idx]

        @ti.kernel
        def _advection_vel(self, dt: ti.f32) -> None:
            n = self.numY
            h = self.h
            h2 = 0.5 * h

            for i, j in ti.ndrange((1, self.numX), (1, self.numY)):
                idx = i * n + j

                if self._s[idx] != 0.0 and self._s[(i - 1) * n + j] != 0.0 and j < self.numY - 1:
                    x = i * h - dt * self._u[idx]
                    y = j * h + h2 - dt * self._avg_v_ti(i, j)
                    self._nU[idx] = self._sample_field_ti(x, y, int(FIELDS.U_field))

                if self._s[idx] != 0.0 and self._s[i * n + j - 1] != 0.0 and i < self.numX - 1:
                    x = i * h + h2 - dt * self._avg_u_ti(i, j)
                    y = j * h - dt * self._v[idx]
                    self._nV[idx] = self._sample_field_ti(x, y, int(FIELDS.V_field))

        def advection_vel(self, dt: float) -> None:
            self._copy_velocity_buffers()
            self._advection_vel(np.float32(dt))
            self._copy_velocity_back()

        @ti.kernel
        def _copy_smoke_buffer(self) -> None:
            for idx in range(self.numCells):
                self._nM[idx] = self._m[idx]

        @ti.kernel
        def _copy_smoke_back(self) -> None:
            for idx in range(self.numCells):
                self._m[idx] = self._nM[idx]

        @ti.kernel
        def _advection_smoke(self, dt: ti.f32) -> None:
            n = self.numY
            h = self.h
            h2 = 0.5 * h

            for i, j in ti.ndrange((1, self.numX - 1), (1, self.numY - 1)):
                idx = i * n + j
                if self._s[idx] != 0.0:
                    u_val = (self._u[idx] + self._u[(i + 1) * n + j]) * 0.25
                    v_val = (self._v[idx] + self._v[i * n + j + 1]) * 0.5
                    x = i * h + h2 - dt * u_val
                    y = j * h + h2 - dt * v_val
                    self._nM[idx] = self._sample_field_ti(x, y, int(FIELDS.S_field))
                else:
                    self._nM[idx] = 0.0

        def advection_smoke(self, dt: float) -> None:
            self._copy_smoke_buffer()
            self._advection_smoke(np.float32(dt))
            self._copy_smoke_back()


FLUID = _TaichiFluid if ti is not None else _NumpyFluid
