#include <stdio.h>
#include <math.h>

static int float2int(float);
static void counter(void);

float quadrat(float x) {
    counter();
    return x * x;
}

int xmod3(float x) {
    counter();
    int tmp = float2int(x);
    return tmp % 3;
}

static int float2int(float x) {
    counter();
    return (int)round(x);
}

static void counter(void) {
    static int count = 0;
    count++;
    printf("math functions called %d times\n", count);
    return;
}