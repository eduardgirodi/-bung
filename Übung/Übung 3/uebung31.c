#include <stdio.h>

struct bruch kuerzen(struct bruch);
int ggT(int, int);

struct bruch {
    int z;
    int n;
};

struct bruch addBruch(struct bruch b1, struct bruch b2) {
    struct bruch tmp;
    struct bruch erg;
    tmp.z = b1.z * b2.n + b2.z * b1.n;
    tmp.n = b1.n * b2.n;
    erg = kuerzen(tmp);
    return erg;
}

struct bruch kuerzen(struct bruch b) {
    struct bruch erg;
    int ggt = ggT(b.z, b.n);
    erg.z = b.z / ggt;
    erg.n = b.n / ggt;
    return erg;
}

int ggT(int a, int b) {
    if(a == 0) {
        return b;
    }
    while(b != 0) {
        int h = a % b;
        a = b;
        b = h;
    }
    return a;
}

int main() {
    struct bruch b1;
    struct bruch b2;
    struct bruch erg;
    b1.z = 3;
    b1.n = 100;
    b2.z = 5;
    b2.n = 36;
    erg = addBruch(b1, b2);
    printf("%d/%d\n", erg.z, erg.n);
    return 0;
}