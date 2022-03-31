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

int istPrim(int p) {
    if(p<2)
        return 0;
    for(int i=2; i<p; i++) {
        if(ggT(p, i) != 1)
            return 0;
    }
    return 1;
}

int main() {
    int x = 2;
    for(int i = 3; i<=500; i++) {
        if(istPrim(i)) {
            if(i-x==2) {
                printf("%d und %d sind Primzahlzwillinge!\n", x, i);
            }
        x = i;
        }
    }
    return 0;
}