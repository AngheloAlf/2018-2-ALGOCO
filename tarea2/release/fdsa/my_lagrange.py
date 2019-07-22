import numpy as np

def my_lagrange(f, A):
    y_list = [f(x) for x in A]
    range_y_list = range(len(y_list))
    def thing_to_be_called(x):
        total = 0
        for k in range_y_list:
            multiplicatoria = 1
            for j in range_y_list:
                if(j != k):
                    multiplicatoria *= np.true_divide(x - A[j], A[k] - A[j])
            total += y_list[k]*multiplicatoria
        return total
    return thing_to_be_called
