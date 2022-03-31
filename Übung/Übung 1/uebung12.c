#include <stdio.h>

float min(float x, float y, float z) {
    return (x<y ? (x<z ? x : z) : (y<z ? y : z));
}

float max(float x, float y, float z) {
    return (x>y ? (x>z ? x : z) : (y>z ? y : z));
}

int main() {
    printf("min(%f, %f, %f) = %f\n", 2.5, 3.5, 1.5, min(2.5, 3.5, 1.5));
    printf("max(%f, %f, %f) = %f\n", 2.5, 3.5, 1.5, max(2.5, 3.5, 1.5));
    return 0;
}