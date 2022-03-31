#include <stdio.h>

typedef struct bruch {
    int z;
    int n;
} Rational;

Rational kuerze(Rational);
int kgV(int, int);
int ggT(int, int);
Rational addiere(Rational, Rational);
Rational subtrahiere(Rational, Rational);
Rational multipliziere(Rational, Rational);
Rational dividiere(Rational, Rational);
float toFloat(Rational);
void ausgabe(Rational);

Rational kuerze(Rational r) {
    Rational erg;
    int ggt = ggT(r.z, r.n);
    erg.z = r.z / ggt;
    erg.n = r.n / ggt;
    return erg;
}

int kgV(int a, int b) {
    return ((a*b)/ggT(a, b));
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

Rational addiere(Rational b1, Rational b2) {
    Rational tmp;
    Rational erg;
    tmp.z = b1.z * b2.n + b2.z * b1.n;
    tmp.n = b1.n * b2.n;
    erg = kuerze(tmp);
    return erg;
}

Rational subtrahiere(Rational b1, Rational b2) {
    Rational tmp;
    Rational erg;
    tmp.z = b1.z * b2.n - b2.z * b1.n;
    tmp.n = b1.n * b2.n;
    erg = kuerze(tmp);
    return erg;
}

Rational multipliziere(Rational b1, Rational b2) {
    Rational tmp;
    Rational erg;
    tmp.z = b1.z * b2.z;
    tmp.n = b1.n * b2.n;
    erg = kuerze(tmp);
    return erg;
}

Rational dividiere(Rational b1, Rational b2) {
    Rational tmp;
    Rational erg;
    tmp.z = b1.z * b2.n;
    tmp.n = b1.n * b2.z;
    erg = kuerze(tmp);
    return erg;
}

float toFloat(Rational r) {
    return 1.0 * r.z / r.n;
}

void ausgabe(Rational r) {
    printf("%d/%d", r.z, r.n);
}

int main() {
    printf("Bitte geben sie den ersten Bruch ein: ");
    Rational n1;
    scanf("%d %d", &n1.z, &n1.n);
    printf("Bitte geben sie den zweiten Bruch ein: ");
    Rational n2;
    scanf("%d %d", &n2.z, &n2.n);
    Rational n3;
    float num1;
    n3 = addiere(n1, n2);
    printf("addiere:\t%d/%d\n", n3.z, n3.n);
    n3 = subtrahiere(n1, n2);
    printf("subtrahiere: \t%d/%d\n", n3.z, n3.n);
    n3 = multipliziere(n1, n2);
    printf("multipliziere: \t%d/%d\n", n3.z, n3.n);
    n3 = dividiere(n1, n2);
    printf("dividiere:\t%d/%d\n", n3.z, n3.n);
    num1 = toFloat(n1);
    printf("n1 -> float: \t%f\n", num1);
}