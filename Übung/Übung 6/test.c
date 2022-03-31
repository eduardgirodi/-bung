#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    int a[10], *p = &a[6];
    printf("%d", p-a);
    return(0);
}