#include <stdio.h>

int ggT(int a, int b) {
    if (a == 0) {
        return b;
    }
    while (b != 0) {
        int h = a % b;
        a = b;
        b = h;
    }
    return a;
}

int main() {
    printf("ggT(%d, %d) = %d\n", 4, 9, ggT(4, 9));
    printf("ggT(%d, %d) = %d\n", 34, 85, ggT(34, 85));
    return 0;
}