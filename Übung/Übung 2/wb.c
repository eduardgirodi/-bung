#include <stdio.h>

int main() {
    printf("Size of char: %d Byte\n", sizeof(char));
    printf("Size of unsigned char: %d Byte\n", sizeof(unsigned char));
    printf("Size of short int: %d Byte\n", sizeof(short int));
    printf("Size of unsigned short int: %d Byte\n", sizeof(unsigned short int));
    printf("Size of int: %d Byte\n", sizeof(int));
    printf("Size of unsigned int: %d Byte\n", sizeof(unsigned int));
    printf("Size of long int: %d Byte\n", sizeof(long int));
    printf("Size of float: %d Byte\n", sizeof(float));
    printf("Size of double: %d Byte\n", sizeof(double));

    int a = 125;
    int b = -39;

    printf("Wert als Zeichen: a = %c, b = %c\n", (char)a, (char)b);
    printf("Wert als unsigned int: a = %u, b = %u\n", (unsigned)a, (unsigned)b);
    printf("Wert als hex: a = %X, b = %X\n", (unsigned)a, (unsigned)b);
    printf("Wert als signed: a = %d, b = %d\n", (signed int)a, (signed int)b);
    printf("Wert als float: a = %.2f, b = %.2f\n", (float)a, (float)b);
    printf("Wert als double: a = %e, b = %e\n", (double)a, (double)b);
    return 0;
}