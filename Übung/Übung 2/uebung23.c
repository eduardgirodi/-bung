#include <stdio.h>
#include <math.h>

double pqplus(double p, double q) {
    return -p/2 + sqrt((p/2)*(p/2)-q);
}

double pqminus(double p, double q) {
    return -p/2 - sqrt((p/2)*(p/2)-q);
}

int main() {
    int a, b, c;
    double p, q;
    printf("Bitte geben Sie einen Wert fuer a ein: ");
    scanf("%d",&a);
    printf("Bitte geben Sie einen Wert fuer b ein: ");
    scanf("%d",&b);
    printf("Bitte geben Sie einen Wert fuer c ein: ");
    scanf("%d",&c);
    printf("Quadratische Gleichung: %d*x^2 + %d*x + %d = 0\n", a, b, c);
    if(((b*b) - (4*a*c)) < 0) {
        printf("Kein reelles Ergebnis.");
    }
    else {
        p = b/a;
        q = c/a;
        printf("Loesungen: x1 = %lf, x2 = %lf", pqplus(p,q), pqminus(p,q));
    }
    return 0;
}