#include <stdio.h>
#include <stdlib.h>
#include "operation.h"

typedef struct term {
    double op1;
    double op2;
    char op;
    double res;
    int err;
} term_t;

term_t parseCmdlineArguments(int argc, char **argv) {
    term_t term;
    term.err = 0;

    if(argc != 4) {
        term.err = -1;
        return term;
    }

    if(sscanf(argv[1], "%lf", &term.op1) != 1) {
        term.err = -2;
        return term;
    }

    if(sscanf(argv[2], "%c", &term.op) != 1) {
        term.err = -2;
        return term;
    }

    if(sscanf(argv[3], "%lf", &term.op2) != 1) {
        term.err = -2;
        return term;
    }

    switch(term.op) {
        case '+':
            term.res = add(term.op1, term.op2);
            break;
        case '-':
            term.res = subtract(term.op1, term.op2);
            break;
        case '*':
            term.res = multiply(term.op1, term.op2);
            break;
        case '/':
            term.res = divide(term.op1, term.op2);
            break;
        default:
            term.err = -3;
    }
    return term;
}

int main(int argc, char **argv) {
    term_t term;
    term = parseCmdlineArguments(argc, argv);

    if(term.err < 0) {
        fprintf(stderr, "%s: Parsing error: %d", argv[0], term.err);
    }
    else {
        printf("%lf %c %lf = %lf", term.op1, term.op, term.op2, term.res);
    }
}