from __future__ import print_function
import numpy as np

def printfAll(A, DP):
    print("\t", end="")
    for i in range(len(A)):
        print(str(A[i])+"\t", end="")
        if(i >= 1):
            print("\t", end="")
    print("\tUwU")
    for i in range(len(DP)):
        print(str(i)+"\t", end="")
        for j in range(len(DP[0])):
            print(str(DP[i][j])+"\t", end="")
        print()
    print()

def dulces(kilos, A):
    A = np.concatenate( [  [-np.inf], A] )
    n = len(A)

    DP = [ [[0, 0] for y in range(n+1)] for x in range(kilos+1)]
    # print(DP)
    # for i in DP:
    #     print(i)
    # exit(0)
    # DP = np.zeros((kilos+1, n+1), dtype=int)


    print(DP)

    for j in range(n-1, 0, -1):
        for i in range(kilos-1, 0, -1):
            print(i, j)
            if kilos - i*A[j] - DP[i+1][j][1] >= 0:
                DP[i][j][0] = DP[i][j+1][0] + int(i)
                DP[i][j][1] = DP[i][j+1][1] + int(i*A[j])
            else:
                pass
                # DP[i][j] = DP[i][j+1]
                # DP[i, j] = np.max([ DP[i, j+1], 1+DP[j,j+1] ])
            printfAll(A, DP)
            # print(A)
            # print(DP)
    return DP[0][1]

print(dulces(8, [2, 3, 5]))