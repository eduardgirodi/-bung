#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *multiply(int *A, int *B, int n) {
    int *C = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            *(C + (i * n + k)) = 0; // C[i*n+k]
            for(int j = 0; j < n; j++) {
                *(C + (i * n + k)) += *(A + (i * n + j)) * *(B + (j * n + k));
            }
        }
    }
    return C;
}

int main()
{
    int A[] = {1, 2, 3, 4, 1, 0, -1, 18, 7};
    int B[] = {1, 0, -1, 2, 1, 0, 5, 0, 1};
    int n = (int)sqrt(sizeof(A) / sizeof(int));
    int *C = multiply(A, B, n);
    for (int i = 0; i < n*n; i++)
    {
        printf("%d ", *(C+i));
    }
    printf("\n");
    free(C);
    return 0;
}