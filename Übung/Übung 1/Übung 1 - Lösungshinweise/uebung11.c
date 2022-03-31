#include <stdio.h>

float
summe(float x, float y) {
    return x+y;
} /* summe */


float
differenz(float x, float y) {
    return x-y;
} /* differenz */


float
produkt(float x, float y) {
    return x*y;
} /* produkt */


float
quotient(float x, float y) {
    if (y == 0.0)
        return 0;

    return x/y;
} /* quotient */


int
runden(float x) {
    return (int)(x>0.0)? (x+0.5) : (x-0.5);
} /* runden */


int 
main(int argc,
     char **argv) {

    /* test cases? */
    printf("%f + %f = %f\n", -3.5, 4.0, summe(-3.5, 4.0));
    printf("%f - %f = %f\n", -3.5, 4.0, differenz(-3.5, 4.0));
    printf("%f * %f = %f\n", -3.5, 4.0, produkt(-3.5, 4.0));
    printf("%f / %f = %f\n", -3.5, 4.0, quotient(-3.5, 4.0));
    printf("%f / %f = %f\n", -3.5, 0.0, quotient(-3.5, 0.0));
    printf("%f / %f = %f\n", 0.0, 4.0, quotient(0.0, 4.0));

    return 0;

} /* main */
