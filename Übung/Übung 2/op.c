#include <stdio.h>
#include <math.h>

float quadrat(float x) {
    return x * x;
}

int mod3(float x) {
    return (int)x%3;
}

double wurzel(float x) {
    return sqrtf(x);
}

double function(float x) {
    return (5*x+3)/(7*(x-1.5));
}

int bitshift(float x) {
    return (int)x<<2;
}

int bitwiseand(float x) {
    return (int)x&0x00f0;
}

int inkrement(float x) {
    int res = (int)x;
    return ++res;
}

int main() {
    float x;
    printf("Please enter a positive floating point number: ");
    scanf("%f", &x);
    printf("x = %f\n\n", x);

    printf("%f^2 = %f\n", x, quadrat(x));
    printf("%f mod 3 = %d\n", x, mod3(x));
    printf("sqrtf(%f) = %lf\n", x, wurzel(x));
    printf("(5*%f+3)/(7*(%f-1.5)) = %lf\n", x, x, function(x));
    printf("%d << 2 = 0x%X\n", (int)x, bitshift(x));
    printf("0x%X & 0x%X = 0x%X\n", (int)x, 0x00f0, bitwiseand(x));
    printf("%d + 1 = %d", (int)x, inkrement(x));
    return 0;
}