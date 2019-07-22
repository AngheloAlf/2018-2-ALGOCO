#include <stdio.h>

#define XOR(a, b) (((a) || (b)) && !((a) && (b)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void inc(int *a, int *m, int size){
    if(*m == -1){
        a[0] = 0;
        *m = 0;
        return;
    }
    int i;
    for(i = 1; a[i] == 1; ++i){
        a[i] = 0;
    }
    a[i] = (a[i] == 0);
    if((a[i] == 0) && *m==i){
        *m = -1;
    }
    else{
        *m = MAX(*m, i);
    }
}

void dec(int *a, int *m, int size){
    if(*m == -1){
        a[0] = -1;
        *m = 0;
        return;
    }

    int i = 0;
    for(; a[i] == -1; ++i){
        a[i] = 0;
    }

    a[i] = (a[i] == 0) ? -1 : 0;
    if((a[i] == 0) && *m==i){
        *m = -1;
    }
    else{
        *m = MAX(*m, i);
    }
}
void printfArr(int *a, int *m, int size){
    printf("%i ", *m);
    for(int i = size-1; i >= 0; --i){
        printf("%i", a[i]);
    }
}

int val(int *a, int *m, int size){
    int result = 0;
    for(int i = 0; i <= *m; ++i){
        result += a[i]<<i;
    }
    return result;
}

int main(){
    int size = 7, m = 0;
    int arr[size];
    for(int i = 0; i < size; ++i){
        arr[i] = 0;
    }

    for(int i = 0; i < 7; ++i){
        inc(arr, &m, size);
        printfArr(arr, &m, size);
        printf(" %i", val(arr, &m, size));
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < 8; ++i){
        dec(arr, &m, size);
        printfArr(arr, &m, size);
        printf(" %i", val(arr, &m, size));
        printf("\n");
    }


    
    return 0;
    

}

