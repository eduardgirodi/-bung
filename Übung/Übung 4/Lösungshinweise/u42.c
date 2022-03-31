#include <stdio.h>

union color{
	struct RGB{unsigned char red, green, blue;}rgb;
	unsigned hex;
};
typedef union color color;


int main(){
	color pix;
	pix.hex=0x56dbc1;
	printf("Color\nred: %x\ngreen: %x\nblue: %x\n", pix.rgb.red, pix.rgb.green, pix.rgb.blue);
	return 0;
}

