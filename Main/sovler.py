import numpy as np
import visualizer
class FLUID:
    # numX,Y are the no of cells and h is the grid spacing
    def __init__(self, density ,numX, numY , h):
        self.density = density
        self.numX = numX + 2 #these are the boundary cells used to calculate for the edge cells (one - one row for each)
        self.numY = numY + 2
        self.h = h #h here is grid spaceing
        self.numCells = self.numX * self.numY
        self.u = np.zeros(self.numCells, dtype=np.float32) #init vel # using np to make arrays that are faster and mem efficient
        self.v = np.zeros(self.numCells, dtype=np.float32)  # final vel
        self.nU = np.zeros(self.numCells, dtype=np.float32)#new u
        self.nV = np.zeros(self.numCells, dtype=np.float32) # new v
        self.p = np.zeros(self.numCells, dtype=np.float32) #pressure
        self.s = np.zeros(self.numCells, dtype=np.float32) #cell obstacle data
        self.m = np.zeros(self.numCells, dtype=np.float32)
        self.nM = np.ones(self.numCells, dtype=np.float32) # used np.ones to fill this array with value "1"
        num = numX * numY

    def integrate_g(self, dt, gravity):
        n = self.numY
        #this set of loops goes through the array/grid on each x step a Y layer is completed
        for i in range(1, self.numX):
            for j in range(1, self.numY - 1):
                if self.s[i*n + j] != 0.0 and self.s[i*n + j-1] != 0.0:
                    self.v[i*n +j] += gravity * dt;


    def incompressibility_solve(self, itt, dt):#step2 that was making the flow incompressible
        #here we will calcuate divergence
        n = self.numY;
        cp = self.density * self.h/dt;

        # this code act as filter of some sort that runs computation on the cell walls or cells with s != 0
        for iter in range(itt): #itterating loop
            #code for going through the cells excluding the boundary cells
            for i in range(1, self.numX-1):
                for j in range(1, self.numY-1):
                    #for checking the boundary S condition
                    if self.s[i*n + j] == 0:
                        continue
                    s = self.s[i*n + j] #making the stuff local here
                    Sx0 = self.s[(i-1)*n + j]
                    Sx1 = self.s[(i+1)*n + j]
                    Sy0 = self.s[i*n + (j-1)]   #id_ing the cells or the boundaries persay
                    Sy1 = self.s[i*n + (j+1)]
                    if s == Sx0 + Sx1 + Sy0 + Sy1:
                        continue
                    divergence = self.u[(i+1)*n+j] - self.u[i*n + j]+ self.v[i*n + (j+1)]- self.v[i*n + j]
                    p = -divergence / s
                    p = p * visualizer.cur_sec["OverRelax"] #updating the presusre current with overelaxation in it. here its 1.9 i think
                    self.p[i*n + j] += cp * p;
                    # updating the values
                    self.u[i*n + j] -= Sx0 *p
                    self.u[(i+1)*n +j] += Sx1 *p
                    self.v[i*n + j] -= Sy0 *p
                    self.v[i*n +(j+1)] += Sy1 * p


    def Extrapolate(self):
        print("Extrapolating")



