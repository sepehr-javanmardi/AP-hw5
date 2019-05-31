import cmath

class PGussSolver:
    def __init__(self,n):
        self.n = n              #Degree of legender
        self.xi = []            #Zeroes of legender
        self.wi = []            #Coeficient
    #Calculate legender polynomial
    def P(self,d,x):
        if d==0:
            return 1;
        if d==1:
            return x;
        else:
            return (1/d)*((2*d -1)*x*self.P(d-1,x) - (d-1)*self.P(d-2,x));
    #Calculate Derivative of legender polynomial
    def DerP(self,d,x):
        return (d/(x*x -1))*(x*self.P(d,x) - self.P(d-1,x));

    def newton(self,epsilon, max_iter):
        '''Approximate solution of P(x)=0 by Newton's method.

        Parameters

        epsilon : number
            Stopping criteria is abs(f(x)) < epsilon.
        max_iter : integer
            Maximum number of iterations of Newton's method.

        '''
        for t in range(self.n):
            xn = cmath.cos(cmath.pi*(t+1-0.25)/(self.n +0.5))
            for i in range(0, max_iter):
                fxn = self.P(self.n,xn)
                if abs(fxn) < epsilon:
                    self.xi.append(xn)
                    break
                Dfxn = self.DerP(self.n,xn)
                if Dfxn == 0:
                    self.xi.append(0)
                    break
                xn = xn - fxn / Dfxn
        return self.xi
    #Calculate Coefficient and Integrate
    def Integrate(self,f,a,b):
        sum = 0;
        for i in range(self.n):
            self.wi.append(2/((1-self.xi[i]*self.xi[i])*(self.DerP(self.n,self.xi[i])**2)))
            sum = sum + ((b-a)/2)*self.wi[i]*f((b-a)*self.xi[i]/2 +((b+a)/2))
        return  sum