#include <stdio.h>
#include <stdlib.h>

int *array() {
    int *arr = (int *)malloc(sizeof(int) * 10);
    for(int i=0; i<10; i++) {
        *(arr + i) = i + 1;
    }
    return arr;
}

int main() {
    int *arr = array();
    for(int i=0; i<10; i++) {
        printf("%d\n", *(arr+i));
    }
    free(arr);
    return 0;
}