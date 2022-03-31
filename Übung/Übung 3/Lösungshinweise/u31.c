#include <stdio.h>
#include <stdlib.h>

void kuerzen(int, int);
int ggT(int, int);
void addBruch(int *, int *, int *);

int main()
{
	int z1[2] = {3, 100};
	int z2[2] = {5, 36};
	int erg[2];
	addBruch(z1, z2, erg);
	printf("%d/%d\n", erg[0], erg[1]);
	return 0;
}
void addBruch(int z1[], int z2[], int erg[])
{
	erg[0] = z1[0] * z2[1] + z2[0] * z1[1];
	erg[1] = z1[1] * z2[1];
	int g = ggT(erg[0], erg[1]);
	erg[0] /= g;
	erg[1] /= g;
}
int ggT(int a, int b)
{
	int g;
	if (a == 0)
		return abs(b);
	if (b == 0)
		return abs(a);
	do
	{
		g = a % b;
		a = b;
		b = g;
	} while (b != 0);
	return abs(a);
}
