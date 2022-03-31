#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int alph[37] = {0};
    for(int i=1; i<argc; i++) {
        for(int j=0; argv[i][j] != '\0'; j++) {
            if(argv[i][j]>='0' && argv[i][j]<='9') {
                ++alph[argv[i][j] - '0'];
            }
            else {
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z') {
                    ++alph[argv[i][j] - 'a' + 10];
                }
                else {
                    ++alph[36];
                }
            }
        }
    }
    for(int i = 0; i < 37; i++) {
        if(alph[i] != 0) {
            if(i < 10) {
                printf("%c: %d\n", '0' + i, alph[i]);
            }
            else {
                if(i != 36) {
                    printf("%c: %d\n", 'a' + i - 10, alph[i]);
                }
                else {
                    printf("Unbekannt: %d\n", alph[36]);
                }
            }
        }
    }
    return 0;
}