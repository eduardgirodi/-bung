#include <stdio.h>
#include <stdlib.h>
#define N 10

int *localArray(){
    int *arr;
    for(int i = 0; i < N; i++){
        *(arr+i) = i + 1;
    }
    return arr;
}

int *otherArray1(){
    int *arr = (int*) malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++){
        *(arr+i) = i + 1;
    }
    return arr;

}

void otherArray2(int* arr){
    for(int i = 0; i < N; i++){
        arr[i] = i + 1;
    }
}

int main(){
    int *arr = localArray();
    for(int i = 0; i < N; i++){
        printf("%d\n", *(arr+i));
    }

    int *arr2 = otherArray1();
    for(int i = 0; i < N; i++){
        printf("%d\n", arr2[i]);
    }
    
    int arr3[10];
    otherArray2(arr3);
    for(int i = 0; i < N; i++){
        printf("%d\n", arr3[i]);
    }
    free(arr2);
    return 0;
}


