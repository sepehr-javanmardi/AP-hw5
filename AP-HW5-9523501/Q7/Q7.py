import numpy as np

def spec(input):
    print(np.unique(np.sort(input[np.where(input % 6 == 0) and input % 6 == 0])))


inp1 = np.array([3, 4, 1, 37, 21, 18, 23, 21, 27, 22, 43, 21])
spec(inp1)

inp2 = np.array([1, 2, 3, 4, 5, 6])
spec(inp2)



