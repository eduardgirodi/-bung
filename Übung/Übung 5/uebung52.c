#include <stdio.h>
#include <stdlib.h>

char getCharAtPos(int value, int pos) {
    value >>= pos;
    return ((value & 1) == 1) ? '1' : '0';
}

char *toBinaryString(int value) {
    char *str;
    if(value == 0) {
        str = malloc(sizeof(char) * 2);
        str[0] = '0';
        str[1] = '\0';
    }
    int length = sizeof(int) * 8;
    int i;
    for(i = length - 1; i >= 0; i--) {
        if(getCharAtPos(value, i) == '1') {
            i++;
            break;
        }
    }
    str = malloc(sizeof(char) * i + 1);
    str[i] = '\0';
    for(int j = 0; j < i; j++) {
        str[j] = getCharAtPos(value, i-j-1);
    }
    return str;
}

int main() {
    int value;
    scanf("%d", &value);
    printf("%s\n", toBinaryString(value));
    return 0;
}