#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

double programacion_dinamica(long n, double a, double b, double c){
    if(0 == n){
        return 0;
    }
    double memoization[n+1], option_a, option_b, option_c;
    memoization[0] = 0;
    for(long i = 1; i < n+1; ++i){
        option_a = i < a ? -INFINITY : 1 + memoization[(long)(i-a)];
        option_b = i < b ? -INFINITY : 1 + memoization[(long)(i-b)];
        option_c = i < c ? -INFINITY : 1 + memoization[(long)(i-c)];

        memoization[i] = MAX(MAX(option_a, option_b), option_c);
    }

    return memoization[n];
}

int main(int argc, char **argv){
    long n;
    double a, b, c;
    int ret = scanf("%li %lf %lf %lf", &n, &a, &b, &c);
    if(ret != 4){
        exit(-1);
    }
    printf("%li\n", (long)programacion_dinamica(n, a, b, c));
    return 0;
}
