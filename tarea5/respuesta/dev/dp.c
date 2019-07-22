#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double **zeros(long x, long y){
    double **mat = (double **)malloc(sizeof(long)*x);
    for(long i = 0; i < x; ++i){
        mat[i] = (double *)calloc(y, sizeof(long));
    }
    return mat;
}

void freeZeros(double **mat, long x){
    for(long i = x-1; i >= 0; --i){
        free(mat[i]);
    }
    free(mat);
}

void printfTable(double **mat, long x, long y){
    for(long i = 0; i < x; ++i){
        printf("[%.0lf", mat[i][0]);
        for (int j = 1; j < y; ++j){
            printf(", %.1lf", mat[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

double *addAtStart(double *arr, long arrSize, double newNumber){
    double *newArr = malloc(sizeof(long) * (arrSize+1));
    *newArr = newNumber;
    for(long i = 0; i < arrSize; ++i){
        newArr[i+1] = arr[i];
    }
    return newArr;
}



double dp(double *arr, long arrSize){
    double *A = addAtStart(arr, arrSize, -INFINITY);
    arrSize += 1;

    double **table = zeros(arrSize + 1, arrSize + 1);

    for(long j = arrSize-1; j >= 0; --j){
        for(long i = 0; i < j +1; ++i){
            printf("%li %li\n", i, j);
            if(A[i] >= A[j]){
                table[i][j] = table[i][j+1];
            }
            else{
                table[i][j] = table[i][j+1] > 1 + table[j][j+1] ? table[i][j+1] : 1 + table[j][j+1];
            }
            printfTable(table, arrSize+1, arrSize+1);
        }
    }

    double result = table[0][1];

    free(A);
    freeZeros(table, arrSize + 1);
    return result;
}

void printfAll(double *A, long arrSize, double **table, long n){
    printf("\t     ");
    for(long x = 0; x < arrSize; ++x){
        printf("%.0lf, ", A[x]);
    }
    printf("\n");

    for(long x = 0; x < n+1; ++x){
        printf("%li\t\t", x);
        for(long y = 0; y < arrSize+1; ++y){
            printf("%.0lf, ", table[x][y]);
        }
        printf("\n");
    }
}

double dulces(long n, double kilosPorPorcion[3]){
    double *A = addAtStart(kilosPorPorcion, 3, -INFINITY);
    long arrSize = 3+1;

    double **table = zeros(n+1, arrSize+1);
    printfTable(table, n+1, arrSize+1);


    for(long j = arrSize-1; j >= 1; --j){
        for(long i = 0; i < j + 1 && i < n + 1; ++i){
            printf("%li %li\n", i, j);

            if(n - i*A[j] >= 0){
                table[i][j] = table[i][j+1]+i;
            }
            else{
                //  table[i][j] = max(table[i][j+1], 1 + table[j][j+1]);
                // table[i][j] = table[i][j+1] > 1 + table[j][j+1] ? table[i][j+1] : 1 + table[j][j+1];
            }

            /*if(A[i] >= A[j]){
                table[i][j] = table[i][j+1];
            }
            else{
                table[i][j] = table[i][j+1] > 1 + table[j][j+1] ? table[i][j+1] : 1 + table[j][j+1];
            }*/
            // printfTable(table, n+1, arrSize+1);
            printfAll(A, arrSize, table, n);
        }
    }
    // printfTable(table, n+1, arrSize+1);
    printfAll(A, arrSize, table, n);


    printf("\t     ");
    for(long x = 0; x < arrSize; ++x){
        printf("%.0lf, ", A[x]);
    }
    printf("\n");

    for(long x = 0; x < n+1; ++x){
        printf("%li\t\t", x);
        for(long y = 0; y < arrSize+1; ++y){
            printf("%.0lf, ", table[x][y]);
        }
        printf("\n");
    }


    free(A);
    freeZeros(table, n+1);
    return 0;
}

int main(){
    /*
    double arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    printf("%lf\n", dp(arr, sizeof(arr)/sizeof(arr[0])));
    */
    double kilosPorPorcion[3] = {2, 3, 5};
    dulces(8, kilosPorPorcion);
    return 0;
}