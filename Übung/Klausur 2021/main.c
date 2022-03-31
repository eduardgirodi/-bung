#include <stdio.h>
#include <stdlib.h>

int *pascal(int n) {
    int *res = malloc(sizeof(int)*(n+1));
    res[0] = 1;
    if(n==0) {
        return res;
    }
    res[n] = 1;
    if(n==1) {
        return res;
    }
    int *arr = malloc(sizeof(int)*n);
    arr = pascal(n-1);
    for(int i=1; i<n; i++) {
        res[i] = arr[i-1] + arr[i];
    }
    free(arr);
    return res;
}

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int *arr = malloc(sizeof(int)*(n+1));
    arr = pascal(n);
    for(int i=0; i<(n+1); i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}