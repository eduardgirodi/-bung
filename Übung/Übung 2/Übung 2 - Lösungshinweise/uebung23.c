#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    float d = (float)b*b - 4*a*c;

    if(d < 0){
        printf("There are no real roots.");
        return 0;
    }
    else
        if(d == 0){
            printf("One double root\nx1 = x2 = %f", -(float)b/(2*a));
            return 0;
        }
        else
            printf("Two real roots:\nx1 = %f\nx2 = %f", (-b+sqrt(d))/(2*a), (-b-sqrt(d))/(2*a));
    return 0;
}
