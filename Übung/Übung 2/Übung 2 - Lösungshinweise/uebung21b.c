#include <stdio.h>

int 
main(int argc,
     char **argv) {

    int a = 125;
    int b = -39;

    printf("Wert als Zeichen: %c %c\n",
           (char)a, (char)b);

    printf("Wert als unsigned int: %u %u\n",
           (unsigned)a, (unsigned)b);

    printf("Wert als hex: %x %x\n",
           (unsigned)a, (unsigned)b);

    printf("Wert als signed: %d %d\n",
           (signed int)a, (signed int)b);

    printf("Wert als float: %.2f %.2f\n",
           (float)a, (float)b);

    printf("Wert als double: %e %e\n",
           (double)a, (double)b);

} /* main */
