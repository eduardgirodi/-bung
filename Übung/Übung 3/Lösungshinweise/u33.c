// Compile: gcc u33.c -o u33 -lm
// run ./u33

#include <stdio.h>
#include <math.h>

float hsqrt(float a, float x0, float x1) {
    x1 = 0.5*(x0+a/x0);
    if((fabs(x1-x0))<0.01){
        return x1;
        }
    x0=x1;
    return  hsqrt(a, x0, x1);
    }

//start value (a+1)/2
float hsqrtMain(float a) {
    return hsqrt(a, (a+1)/2, a);
}

int main() {
    float a;
    scanf("%f", &a);
    if (a < 0)
    	printf("Number must be >0\n");
    else{
	float result;
    	result = hsqrtMain(a);
    	printf("Result heron : %f\n", result);
    	result = sqrt(a);
    	printf("Result sqrt(): %f\n", result);
	}
    return 0;
}

