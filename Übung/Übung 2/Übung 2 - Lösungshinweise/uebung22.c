#include <stdio.h>
#include <math.h>


float
quadrat(float x) {

    return x*x;

} /* quadrat */


float
xmod3(float x) {

    return fmodf(x, 3);

} /* xmod3 */


double
wurzel(float x) {

    return sqrt(x);

} /* wurzel */


double
function(float x) {

    return (5*x+3)/(7*(x-1.5));

} /* function */


/*
** You can bitshift a floating point number, of course. Have a
** look at https://www.h-schmidt.net/FloatConverter/IEEE754.html
** and key in your floating point number x. Next shift all ones 
** two positions to the left and see what happens.
**
** One way to implement that is a union (pointers will also do
** the trick): Write the floating point component, bitshift the
** int component with standard C bitshift operators and read back 
** the floating point component.
*/
double
bitshift(float x) {

    union {
        float f;
        int   i;
    } bitty;

    bitty.f = x;
    bitty.i <<= 2;

    return bitty.f;

} /* bitshift */


/*
** Another variant is to cast the floating point type to
** an int type and just use standard C bitshift operators.
** The result obviously differs from the approach we used
** in the function bitshift(float).
*/
int
bitshift2(float x) {

    int i = (int)x;
    i <<= 2;

    return i;

} /* bitshift2 */


/* 
** Same procedure as with bitshifting. We simply
** cast the floating point type to an int type.
*/
int
bitwiseand(float x) {

    int i = (int)x;
    i = i & 0x00f0;

    return i;

} /* bitwiseand */


/* 
** Same procedure as with bitshifting. We simply
** cast the floating point type to an int type.
*/

int
increment(float x) {

    int i = (int)x;
    return ++i;

} /* increment */


int 
main(int argc,
     char **argv) {

    float f;

    printf("Floating point number, please: ");
    scanf("%f", &f);
    printf("Oh, you chose %f, what an excellent choice ;)\n\n", f);

    printf("%f^2 = %f\n", f, quadrat(f));
    printf("%f mod 3 = %f\n", f, xmod3(f));
    printf("sqrt(%f) = %f\n", f, wurzel(f));
    printf("(5*%f+3)/(7*(%f-1.5)) = %f\n", f, f, function(f));
    printf("with float: %f << 2 = %e\n", f, bitshift(f));
    printf("with int: %d << 2 = %x\n", (int)f, bitshift2(f));
    printf("with int: %d & %d = %d\n", (int)f, 0x00f0, bitwiseand(f));
    printf("%d++ = %d\n", (int)f, increment(f));

    return 0;

} /* main */
