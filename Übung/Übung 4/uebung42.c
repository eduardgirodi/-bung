#include <stdio.h>

typedef union color
{
    struct rgb
    {
        unsigned char r, g, b;
    } rgb;
    unsigned hex;
} color;

int main()
{
    color magenta;
    magenta.hex = 0xff00ff;
    printf("Magenta RGB values: R=0x%X, G=0x%X B=0x%X", magenta.rgb.r, magenta.rgb.g, magenta.rgb.b);
    return 0;
}