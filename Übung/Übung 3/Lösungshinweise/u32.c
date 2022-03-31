#include <stdio.h>
#include <math.h>

double gl3Grad(double x0, double x2, double interval){
    double f=0;
    for(double x1=x0; x1<x2; x1+=interval){
        f += ((pow(x0,3)-2*x0*x0-x0+2)+(pow(x1,3)-2*x1*x1-x1+2))*interval/2;
        x0=x1;
    }
    return f;
}

double sinc(double x0, double x2, double interval){
    double f=0, g=0, g0=0, g1=0;
    for(double x1=x0; x1<x2; x1+=interval){
        if(x0==0)
            g0=1;
        else
            g0=sin(x0)/x0;
        if(x1==0)
            g1=1;
        else
            g1=sin(x1)/x1;
        g += (g0+g1)*interval/2;
        x0=x1;
    }
    return g;
}

int main(){
    double a, b, inter, f, g;
    scanf("%lf%lf%lf", &a, &b, &inter);
    f=gl3Grad(a, b, inter);
    printf("f: %f\n", f);
    scanf("%lf%lf%lf", &a, &b, &inter);
    g=sinc(a, b, inter);
    printf("g: %f\n", g);
    return 0;
}


