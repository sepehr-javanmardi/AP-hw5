import cmath
from time import time as epochTime
import subprocess
import PGS
from prettytable import PrettyTable
import matplotlib.pyplot as plt
import numpy as np

columns = ('Degree of legender polynominal', 'Python running time(ms)', 'C++ running time(ms)')
t = PrettyTable(columns)
PT=[]
CT=[]
for i in range (20):
    d=i+1

    start = epochTime()
    a = PGS.PGussSolver(d);
    a.newton(0.001, 1000)
    a.Integrate(lambda x: x ** 3 / (x + 1) * cmath.cos(x ** 2), 0, 1)
    PTime=(epochTime() - start) * 1000
    PT.append(PTime)

    start = epochTime()
    subprocess.call(["ConsoleApplication2.exe", str(d)]);
    CTime= (epochTime() - start) * 1000
    CT.append(CTime)
    t.add_row([i+1, PTime ,CTime])

print(t)
rows = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10',
        '11', '12', '13', '14', '15', '16', '17', '18',
        '19', '20']
cell_text = []
for i in range(20):
    cell_text.append(list())
    cell_text[i].append(rows[i])
    cell_text[i].append(PT[i])
    cell_text[i].append(CT[i])

fig=plt.figure()
ax = fig.add_subplot(111)
ax.xaxis.set_visible(False)
ax.yaxis.set_visible(False)
ax.axis('off')
ax.autoscale(enable=True)
the_table = ax.table(cellText=cell_text,
          colLabels=columns,
          loc='center', cellLoc='center')
fig.show()

pyRes = np.asarray(PT)
cRes = np.asarray(CT)
r = np.arange(1, 21, 1)
dig = plt.figure()
ax = dig.add_subplot(111)
plt.plot(r, pyRes, '-r', label='Python')
plt.plot(r, cRes, '-b', label='C++')
plt.legend(loc='upper left')
plt.title('Running Time Diagrams', fontsize=12)
plt.xlabel('Degree of legender Polynomial', fontsize=12)
plt.ylabel('Running Time', fontsize=12)
plt.savefig('result.pdf')
dig.show()
