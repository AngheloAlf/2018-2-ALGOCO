import numpy as np

def my_divided_differences(f, A):
    aux = [f(x) for x in A]
    len_ = len(A)
    for j in range(1, len_):
        for i in range(len_-1, j-1, -1):
            aux[i] = np.true_divide(aux[i]-aux[i-1], A[i]-A[i-j], dtype=np.float64)

    def thing_to_be_called(xx):
        result = aux[0]
        olds = []
        for i in range(1, len(aux)):
            substraction = (xx - A[i-1])
            actualMultiplication = aux[i]*substraction
            for j in olds:
                actualMultiplication *= j
            result += actualMultiplication
            olds.append(substraction)
        return result

    return thing_to_be_called
