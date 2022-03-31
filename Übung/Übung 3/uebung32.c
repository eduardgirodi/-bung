#include <stdio.h>
#include <math.h>

double function(double, char);

double integral(double x1, double x2, double interval, char f) {
    double res = 0.0;
    for (double i = x1; i < x2; i += interval) {
        res += (function(i, f) + function(i + interval, f)) * interval / 2;
    }
    return res;
}

double function(double x, char f) {
    switch (f) {
        case 'f':
            return (pow(x, 3) - 2 * x * x - x + 2);
        case 'g':
            return (x == 0) ? 1 : sin(x) / x;
        default:
            return 0.0;
    }
}

int main()
{
    double a, b, inter;
    scanf("%lf%lf%lf", &a, &b, &inter);
    printf("f: %f\n", integral(a, b, inter, 'f'));
    scanf("%lf%lf%lf", &a, &b, &inter);
    printf("g: %f\n", integral(a, b, inter, 'g'));
    return 0;
}