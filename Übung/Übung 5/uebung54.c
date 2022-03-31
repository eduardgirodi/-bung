#include <stdio.h>
#include <stdlib.h>

int strlength(char *string) {
    int i = 0;
    while(*(string + i) != '\0') {
        i++;
    }
    return i;
}

int isPalindrome(char *string) {
    int length = strlength(string);
    for(int i = 0; i < length / 2; i++) {
        if(*(string + i) != *(string + length - 1 - i)) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    int pal = isPalindrome(argv[1]);
    if(pal == 1) {
        printf("String %s ist ein Palindrom\n", argv[1]);
    }
    else {
        printf("String %s ist kein Palindrom\n", argv[1]);
    }
    return 0;
}