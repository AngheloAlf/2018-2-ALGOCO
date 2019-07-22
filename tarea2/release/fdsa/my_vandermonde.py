import numpy as np

def my_vandermonde(f, A):
    matrix = []
    for j in np.arange(len(A)):
        aux = []
        for i in np.arange(len(A)):
            aux.append(np.power(A[j], i, dtype=np.float64))
        matrix.append(np.array(aux))
    matrix = np.array(matrix)
    y_list = np.array([f(x) for x in A])
    coef = np.linalg.solve(matrix, y_list)
    def thing_to_be_called(x):
        return sum([coef[i] * np.power(x, i) for i in range(len(coef))]) 
    return thing_to_be_called
