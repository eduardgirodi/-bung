#include <math.h>
#include "operation.h"

#ifndef FP_NAN
/* Hmmmja, how to define NAN with all required properties... */
#define FP_NAN 0
#endif


float
add(float op1, float op2) {

    return op1+op2;

} /* add */


float
subtract(float op1, float op2) {

    return op1-op2;

} /* subtract */


float
multiply(float op1, float op2) {

    return op1*op2;

} /* multiply */


float
divide(float op1, float op2) {

    if (0 != op2)
        return op1/op2;
    else
        return FP_NAN;

} /* divide */
