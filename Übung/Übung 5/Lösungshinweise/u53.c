# include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* Multiply(int *A, int *B, int n){
    int* C = malloc(sizeof(int) * n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(C + (n*i+j)) = 0; // C[n*i+j]

            for (int x = 0; x < n; x++) {
                *(C + (n*i+j)) += *(A + (n * i + x)) * *(B + (n * x + j));
            }
        }
    }
    return C;
}

int main(){
    int A[]= {1,2,3,4,1,0,-1,18,7};
    int B[] ={1,0,-1,2,1,0,5,0,1};
    int n = (int)sqrt(sizeof(A)/sizeof(int));
    int *C = Multiply(A, B, n);
    for(int i = 0; i < n*n ; i++)
        printf("%d  ", *(C+i));
    printf("\n");
    free(C);
    return 0;
}

