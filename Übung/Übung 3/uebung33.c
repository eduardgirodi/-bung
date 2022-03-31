#include <stdio.h>
#include <math.h>

double hsqrtRec(double a, double x0, double x1)
{
    x1 = 0.5 * (x0 + a / x0);
    if (fabs(x1 - x0) < 0.001)
    {
        return x1;
    }
    x0 = x1;
    return hsqrtRec(a, x0, x1);
}

// Startwert x0 = (a+1)/2;
double hsqrt(double a)
{
    return hsqrtRec(a, (a + 1) / 2, 0);
}

int main()
{
    double a;
    printf("a = ");
    scanf("%lf", &a);
    printf("hsqrt(%f) = %f\n", a, hsqrt(a));
    printf("sqrt(%f) = %f\n", a, sqrt(a));
    return 0;
}