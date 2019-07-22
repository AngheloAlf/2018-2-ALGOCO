import numpy as np

def lis(A):
    A = np.concatenate( [  [-np.inf], A] )
    n = len(A)

    DP = np.zeros((n+1, n+1), dtype=int)
    print(DP)

    for j in range(n-1, 0, -1):
        for i in range(0, j+1):
            print(i, j)
            if A[i] >= A[j]:
                DP[i, j] = DP[i, j+1]
            else:
                DP[i, j] = np.max([ DP[i, j+1], 1+DP[j,j+1] ])
            print(DP)
    return DP[0, 1]


print(lis([10, 22, 9, 33, 21 ,50 ,41 ,60]))