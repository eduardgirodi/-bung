#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void toLowerCase(char text[]) {
    for(int i=0; i<strlen(text); i++) {
        if(text[i]>('A'-1) && text[i]<('Z'+1)) {
            text[i] += 32;
        }
    }
}

void removeSpaces(char text[]) {
    int count = 0;
    for(int i=0; i<strlen(text); i++) {
        if(text[i] != ' ') {
            text[count++] = text[i];
        }
    }
    text[count] = '\0';
}

void replaceJ(char text[]) {
    for(int i=0; i<strlen(text); i++) {
        if(text[i] == 'j') {
            text[i] = 'i';
        }
    }
}

void even(char text[]) {
    int length = strlen(text);
    if(length%2 != 0) {
        text[length++] = 'x';
        text[length] = '\0';
    }
}

void fillDoubles(char text[]) {
    for(int i=0; i<strlen(text); i+=2) {
        if(text[i] == text[i+1]) {
            for(int j=strlen(text)+1; j>i+1; j--) {
                text[j] = text[j-1];
            }
            text[i+1] = 'x';
        }
    }
}

void prepareKey(char text[]) {
    removeSpaces(text);
    toLowerCase(text);
}

void preparePlain(char text[]) {
    removeSpaces(text);
    toLowerCase(text);
    replaceJ(text);
    fillDoubles(text);
    even(text);
}

//return 1 if char c is in text[]
int checkForChar(char text[], char c) {
    for(int i=0; i<strlen(text); i++) {
        if(text[i] == c) {
            return 1;
        }
    }
    return 0;
}

//return 1 if char c is in table[][]
int checkTableForChar(char table[5][5], char c) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++)  {
            if(table[i][j] == c) {
                return 1;
            }
        }
    }
    return 0;
}

void generateKeyTable(char key[], char table[5][5]) {
    int count = 0;
    for(int i=0; i<strlen(key); i++) {
        if(checkTableForChar(table, key[i]) == 0 && key[i]!='j') {
            table[(count/5)][(count%5)] = key[i];
            //printf("Count: %d", count);
            count++;
        }
    }
    for(int i=0; i<26; i++) {
        char a = 'a'+i;
        if(checkTableForChar(table, a)==0 && a!='j') {
            table[(count/5)][(count%5)] = a;
            //printf("Count: %d", count);
            count++;
        }
    }
}

void search(char keyT[5][5], char a, char b, int arr[4]) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++)  {
            if(keyT[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            else if(keyT[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

void encrypt(char plain[], char keyT[5][5]) {
    for(int i=0; i<strlen(plain); i+=2) {
        char a = plain[i];
        char b = plain[i+1];
        int pos[4];
        search(keyT, a, b, pos);
        if(pos[0] == pos[2]) {
            plain[i] = keyT[pos[0]] [((pos[1]+1)%5)];
            plain[i+1] = keyT[pos[2]] [((pos[3]+1)%5)];
        }
        else if(pos[1] == pos[3]) {
            plain[i] = keyT[((pos[0]+1)%5)][pos[1]];
            plain[i+1] = keyT[((pos[2]+1)%5)][pos[3]];
        }
        else {
            plain[i] = keyT[pos[0]][pos[3]];
            plain[i+1] = keyT[pos[2]][pos[1]];
        }
    }
}

int main() {
    char key[MAX], str[MAX];

    strcpy(key, "Extra Wurst");
    prepareKey(key);
    printf("Key: %s\n", key);

    printf("Key table:\n");
    char keyT[5][5];
    generateKeyTable(key, keyT);
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++)  {
            printf("%c",keyT[i][j]);
        }
        printf("\n");
    }
    strcpy(str, "c macht spass");
    preparePlain(str);
    printf("Plain text: %s\n", str);

    encrypt(str, keyT);

    printf("Encrypted text: %s\n", str);
}