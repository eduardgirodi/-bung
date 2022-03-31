#include <stdio.h>
#include <stdlib.h>

char getCharAtPos(int value, int pos){
    value >>= pos;
    return ((value & 1) == 1) ? '1' : '0';
}

char* toBinaryString(int value){
    char *string;
   if(value == 0){
        string = (char*) malloc(sizeof(char) * 2);
        string[1] = '\0';
        string[0] = '0';
        return string;
    }
    int length = sizeof(int) * 8;
    int i;
    for(i = length -1 ; i >=0 ; i--){
        if(getCharAtPos(value, i) == '1'){
            i++;
            break;
        }
    }
    string = (char*)malloc(sizeof(char) * i + 1);
    string[i] = '\0';
    int j = 0;
    while(j < i){
        string[j++] = getCharAtPos(value, i-j-1);
    }
    return string;
}
int main(){
    int value;
    scanf("%d", &value);
    printf("%s\n", toBinaryString(value));
return 0;

}

