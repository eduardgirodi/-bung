#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mathemat.h"


static int float2int(float);
static void counter(void);

float
quadrat(float n) {
    counter();
    return n*n;
}


int
xmod3(float x) {
    counter();
    int tmp = float2int(x);
    return tmp % 3;
}


static int
float2int(float x) {

    return (int)round(x);
}


static void
counter(void) {
    static int counter = 0;
    counter++;
    printf("math functions called %d times\n", counter);
    return;
}
