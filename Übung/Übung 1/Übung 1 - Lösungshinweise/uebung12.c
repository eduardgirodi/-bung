#include <stdio.h>

float
max(float x, float y, float z) {
    return (x < y ? (y < z ? z : y) : (x < z ? z : x));
} /* max */


float
min(float x, float y, float z) {
    return (x > y ? (y > z ? z : y) : (x > z ? z : x));
} /* min */


int 
main(int argc,
     char **argv) {

    /* test cases? */
    printf("max(%f, %f, %f) = %f\n", 2.5, 3.5, 1.5, max(2.5, 3.5, 1.5));
    printf("min(%f, %f, %f) = %f\n", 2.5, 3.5, 1.5, min(2.5, 3.5, 1.5));

    return 0;

} /* main */
