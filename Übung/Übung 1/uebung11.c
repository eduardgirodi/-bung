#include <stdio.h>

float summe(float x, float y) {
    return x + y;
}

float differenz(float x, float y) {
    return x - y;
}

float produkt(float x, float y) {
    return x * y;
}

float quotient(float x, float y) {
    if(y==0.0)
        return 0.0;
    return x / y;
}

int runde(float x) {
    if(x>0.0) {
        return x+0.5;
    }
    else {
        return x-0.5;
    }
}

int main() {

    printf("%f + %f = %f\n", -3.5, 4.0, summe(-3.5, 4.0));
    printf("%f - %f = %f\n", -3.5, 4.0, differenz(-3.5, 4.0));
    printf("%f * %f = %f\n", -3.5, 4.0, produkt(-3.5, 4.0));
    printf("%f / %f = %f\n", -3.5, 4.0, quotient(-3.5, 4.0));
    printf("%f / %f = %f\n", -3.5, 0.0, quotient(-3.5, 0.0));
    printf("%f / %f = %f\n", 0.0, 4.0, quotient(0.0, 4.0));

    return 0;
}