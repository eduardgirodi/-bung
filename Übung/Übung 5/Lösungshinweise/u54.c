#include <stdio.h>

int strlength(char *string){
        int len=0;
        while(*(string+len) != '\0')
                ++len;
        return len;
}
int is_palindrome(char *string){
        int len = strlength(string);
        int  i = 0, ret;
        while(i<=len/2-1){
                if(*(string+i) == *(string+len-(1+i))){
                        ret = 0;
                        i++;
                        continue;
                }
                else{
                        ret = 1;
                break;
                }
        }
         return ret;
        }

int main(int argc, char **argv){
        int pal = is_palindrome(argv[1]);
        if(pal == 0)
                printf("String %s ist ein Palindrom\n", argv[1]);
        else
                printf("String %s ist kein Palindrom\n", argv[1]);
        return 0;
}
