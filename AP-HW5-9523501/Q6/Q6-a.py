#Question6
import cmath
from time import time as epochTime
import subprocess
#PGS is a module
import PGS

print("please inter degree of legender:")
d = int(input())

start = epochTime()
#Make an object
a = PGS.PGussSolver(d);
#Set the presition of newton method
a.newton(0.001,1000)
print("Result of Puthon code (n =",d,") :",a.Integrate(lambda x: x**3/(x+1)*cmath.cos(x**2),0,1))
print("Python Running time is :",(epochTime()-start)*1000,"ms")

start = epochTime()
subprocess.call(["ConsoleApplication2.exe",str(d)])
print("C++ Running time is :",(epochTime()-start)*1000,"ms")



