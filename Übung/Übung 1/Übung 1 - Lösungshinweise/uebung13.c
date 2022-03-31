#include <stdio.h>

/* Euklid */
/* https://en.wikipedia.org/wiki/Euclidean_algorithm */
int
ggT(int a, int b) {

    while (b != 0 ) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;

} /* ggT */

int 
main(int argc,
     char **argv) {

    /* test cases? */
    printf("ggT(4, 9)= %d\n", ggT(4, 9));
    printf("ggT(34, 85)= %d\n", ggT(34, 85));

    return 0;

} /* main */
