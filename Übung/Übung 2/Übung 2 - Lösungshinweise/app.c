#include <stdio.h>
#include "mathemat.h"

int
main(int argc, char **argv) {
    printf("I'm main\n");

    float f = 31.42592;
    
    printf("quadrat(%f) = %f\n", f, quadrat(f));
    printf("xmod3(%f) = %d\n", f, xmod3(f));
    printf("quadrat(%f) = %f\n", f, quadrat(f));
    printf("quadrat(%f) = %f\n", f, quadrat(f));
    
}
