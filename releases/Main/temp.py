import sys
import time

import numpy as np

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


def main():
    sim = HeadlessWindTunnel(grid_w=80, grid_h=40, iterations=20)
    sim.set_obstacle_circle(cx=30, cy=20, radius=5, solid=True)

    total_steps = 5
    start = time.perf_counter()
    sim.step(total_steps)
    elapsed = time.perf_counter() - start

    speed = sim.speed_field()
    smoke = sim.smoke_field()

    print(f"steps: {total_steps}")
    print(f"elapsed_seconds: {elapsed:.3f}")
    print(f"steps_per_second: {total_steps / elapsed:.2f}")
    print(f"max_speed: {float(np.max(speed)):.3f}")
    print(f"mean_smoke: {float(np.mean(smoke)):.3f}")


if __name__ == "__main__":
    main()
