#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

double fuerza_bruta(long n, double a, double b, double c){
    if(0 >= n){
        return 0;
    }
    double option_a = n < a ? -INFINITY : 1 + fuerza_bruta(n-a, a, b, c);
    double option_b = n < b ? -INFINITY : 1 + fuerza_bruta(n-b, a, b, c);
    double option_c = n < c ? -INFINITY : 1 + fuerza_bruta(n-c, a, b, c);

    return  MAX(MAX(option_a, option_b), option_c);
}

int main(int argc, char **argv){
    long n;
    double a, b, c;
    int ret = scanf("%li %lf %lf %lf", &n, &a, &b, &c);
    if(ret != 4){
        exit(-1);
    }
    printf("%li\n", (long)fuerza_bruta(n, a, b, c));
    return 0;
}
