import numpy as np
class FLUID:

    # numX,Y are the no of cells and h is the grid spacing
    def __init__(self, density ,numX, numY , h):
        self.density = density
        self.numX = numX + 2 #these are the boundary cells used to calculate for the edge cells (one - one row for each)
        self.numY = numY + 2
        self.h = h
        self.numCells = self.numX * self.numY
        self.u = np.zeros(self.numCells, dtype=np.float32) # using np to make arrays that are faster and mem efficient
        self.v = np.zeros(self.numCells, dtype=np.float32)
        self.nU = np.zeros(self.numCells, dtype=np.float32)
        self.nV = np.zeros(self.numCells, dtype=np.float32)
        self.p = np.zeros(self.numCells, dtype=np.float32)
        self.s = np.zeros(self.numCells, dtype=np.float32)
        self.m = np.zeros(self.numCells, dtype=np.float32)
        self.nM = np.ones(self.numCells, dtype=np.float32) # used np.ones to fill this array with value "1"
        num = numX * numY

    def integrate_d(self, dt, gravity):
        n = self.numY
        #this set of loops goes through the array/grid on each x step a Y layer is completed
        for i in range(1, self.numX):
            for j in range(1, self.numY - 1):
                if self.s[i*n + j] != 0.0 and self.s[i*n + j-1] != 0.0:
                    self.v[i*n +j] += gravity * dt;


    def advect_v(self):
        print("Advection of velocity")



