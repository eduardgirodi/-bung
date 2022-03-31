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
istPrim(int n) {

    int i;

    if (n < 2)
        return 0;

    for (i=2; i<n; i++) {
        if (ggT(n, i) != 1)
            return 0;
    }

    return 1;

} /* istPrim */


int 
main(int argc,
     char **argv) {

    int p1 = 2; /* first prime */ 
    int i = 0;

    for (i = 1; i <= 500; i++) {

        if (istPrim(i)) {
            if (i-p1 == 2) {
                printf("%d : %d\n", p1, i);
            }
            p1 = i;
        }

    }

    return 0;

} /* main */
