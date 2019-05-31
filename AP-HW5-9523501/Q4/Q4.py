import math
import random

def IsInCircle(x, y):
    if (x ** 2 + y ** 2 < 1):
        return True
    else:
        return False

def Find():
    margin = 0.01
    error = 1
    estPI = 3.1415

    inC = 0
    outC = 0

    while (error > margin):
        x = random.random()
        y = random.random()

        if IsInCircle(x, y):
            inC += 1
        else:
            outC += 1

        estPI = 4*(inC)/(outC + inC)
        error = abs(estPI - math.pi)

    print(f'The number of points needed to estimate pi is : {inC + outC}')
    print('The estimated pi is : ', '{0:.5f}'.format(estPI))

    return (inC + outC), estPI

n = int(input('Please enter a number'))

PI = 0
NUMBER = 0
for i in range(n):
    p, q = Find()

    PI += q
    NUMBER += p

PI = PI / n
NUMBER = round(NUMBER / n)

print(f'The number of points, on average, needed to estimate pi is : {NUMBER}')
print('The estimated pi, on average, is : ', '{0:.5f}'.format(PI))
print(f'And the Error is : ', '{0:.5f}'.format(abs(PI - math.pi)))


