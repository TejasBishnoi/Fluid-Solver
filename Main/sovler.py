import numpy as np
import visualizer


class FIELDS:
    U_field = 1
    V_field = 2
    S_field = 3


# -----------SOLVER STARTED-----------
class FLUID:
    #used for clamping the values of what ever is in here, is used in the sample field function
    def clamp(self ,val , min_val , max_val):
        return max(min(val , max_val), min_val)

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
        n = self.numY
        cp = self.density * self.h/dt

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
                    p = p * visualizer.cur_SEC.cur_sec["OverRelax"] #updating the presusre current with overelaxation in it. here its 1.9 i think
                    self.p[i*n + j] += cp * p;
                    # updating the values
                    self.u[i*n + j] -= Sx0 *p
                    self.u[(i+1)*n +j] += Sx1 *p
                    self.v[i*n + j] -= Sy0 *p
                    self.v[i*n +(j+1)] += Sy1 * p

    #  this Extrapolate function, to be simple just copy the value of adjacent interior cell to the boundary cell so that its stable
    # aka zero gradient Neumann condition
    def Extrapolate(self):
        n = self.numY
        for i in range(0 , self.numX):
            self.u[i*n + 0] = self.u[i*n +1]
            self.u[i*n + self.numY-1] = self.u[i*n + self.numY-2]

        for j in range(0 , self.numY):
            self.v[0*n + j] = self.v[1*n + j]
            self.v[(self.numX-1)*n +j] = self.v[(self.numX-2)*n + j]


    def sampleFields(self,x,y,field):
        n = self.numY
        h = self.h
        h1 = 1.0/h
        h2 = 0.5 * h

        #to prevent the values from going out of bounds so that positon comes out accureate
        x = self.clamp(x, h, self.numX*h)
        y = self.clamp(y,h, self.numY *h)

        dx = 0.0
        dy = 0.0

        f = None
        match field:
            case FIELDS.U_field:
                f = self.u
                dy = h2

            case FIELDS.V_field:
                f = self.v
                dx = h2

            case FIELDS.S_field:
                f = self.m
                dx = h2
                dy = h2

        #this is still a little unclear to me
        #this code is figuring out Which square am I in, and where exactly inside that square?
        x0 = min(int((x -dx)*h1), self.numX-1)
        tx = ((x - dx) - x0 * h) * h1
        x1 = min(x0 +1, self.numX-1)

        y0 = min(int((y - dy)*h1), self.numY-1)
        ty = ((y - dy) - y0 * h) * h1
        y1 = min(y0 +1, self.numY-1)

        sx = 1.0 - tx
        sy = 1.0 - ty
        val = sx*sy * f[x0*n + y0] + tx*sy * f[x1*n + y0] + tx*ty * f[x1*n + y1] + sx*ty * f[x0*n + y1]

        return val

    def avg_U(self, i, j):
        n = self.numY
        u = (self.u[i*n + j-1]+ self.u[i*n + j]+ self.u[(i+1)*n + j-1]+ self.u[(i+1)*n + j+1])*0.25 #0.25 for 1/4
        return u

    def avg_V(self, i, j):
        n = self.numY
        v = (self.v[(i-1)*n + j] + self.v[i*n + j] + self.v[(i-1)*n + j+1] + self.v[i*n + j+1]) * 0.25
        return v

    def advection_vel(self ,dt):
        #copying over the values of arrays to nU and nV
        self.nU[:] = self.u
        self.nV[:] = self.v

        n = self.numY
        h = self.h
        h2 = 0.5*h

        for i in range(1,self.numX):
            for j in range(1,self.numY):
                #something related to cnt++ dont know what this is

                #for U component
               #Only update if this is fluid, not a wall.
                if (self.s[i*n +j] != 0.0) and (self.s[(i-1)*n +j] != 0.0) and (j < self.numY-1):
                    # to get the current position
                    x = i*h
                    y = j*h + h2
                    u = self.u[i*n + j]
                    v = self.avg_V(i , j)
                    #backtracing
                    x = x - dt*u
                    y = y - dt*v
                    u = self.sampleFields(x,y, FIELDS.U_field)
                    self.nU[i*n + j] = u

                #for V component
                if (self.s[i*n + j] != 0.0) and (self.s[i*n + j-1] != 0.0) and (i < self.numX - 1):
                    x = i*h + h2
                    y = j*h
                    u = self.avg_U(i , j)
                    v = self.v[i*n + j]
                    x = x - dt*u
                    y = y - dt*v
                    v = self.sampleFields(x,y, FIELDS.V_field)
                    self.nV[i*n + j] = v

        #giving / updating the values
        self.u[:] = self.nU
        self.v[:] = self.nV

    #for smoke boi
    def advection_smoke(self,dt):
        self.nU[:] = self.m
        n = self.numY
        h = self.h
        h2 = 0.5*h

        for i in range (1, self.numX -1):
            for j in range(1, self.numY -1):
                if (self.s[i*n + j] != 0.0):
                    u = (self.u[i*n + j] + self.u[(i+1)*n + j])*0.25
                    v = (self.v[i*n + j] + self.v[i*n + j+1]) * 0.5
                    x = i * h + h2 - dt * u
                    y = j * h + h2 - dt * v
                self.nM[i*n + j] = self.sampleFields(x,y, FIELDS.S_field)

        self.m[:] = self.nM

# -----------SOLVER ENDED-----------






