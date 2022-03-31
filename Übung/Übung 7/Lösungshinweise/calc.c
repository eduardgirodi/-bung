#include <stdio.h>
#include <string.h>
#include <math.h>
#include "operation.h"


typedef struct {
    float op1;
    float op2;
    union {
        float (*oper)(float, float);
        long err;
    };
    char op;
} term_t;


term_t
parseCmdlineArguments(int argc, char **argv) {
    term_t term;

    term.err = 0;

    /* We want exactly four arguments */
    if (argc != 4) {
        term.err = -1;
        goto ret;
    }


    /* Parse operator and operands and signal
       parse errors (if needed). */
    if (1 != sscanf(argv[1], "%f", &term.op1)) {
        term.err = -2;
        goto ret;
    }

    if (1 != sscanf(argv[3], "%f", &term.op2)) {
        term.err = -2;
        goto ret;
    }

    if (1 != sscanf(argv[2], "%c", &term.op)) {
        term.err = -2;
        goto ret;
    }

    switch (term.op) {
    case '+' : {
        term.oper = &add;         
        break;
    }

    case '-' : {
        term.oper = &subtract;
        break;
    }

    case '*' : {
        term.oper = &multiply;
        break;
    }

    case '/' : {
        term.oper = &divide;
        break;
    }

    default:
        term.err = -3;

    } 

 ret:
    return term;

} /* */


int 
main(int argc,
     char **argv) {

    term_t term;

    term = parseCmdlineArguments(argc, argv);
    if (term.err < 0) {
        fprintf(stderr, "%s: Parsing error: %ld. Exit.\n",
        argv[0], term.err);
        return 1;
    }

    printf("%f %c %f = %f\n", term.op1, term.op, term.op2,
           term.oper(term.op1, term.op2));

    return 0;

} /* main */
