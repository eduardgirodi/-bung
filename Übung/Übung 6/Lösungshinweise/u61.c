#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10  // Maximum number of persons
#define LEN 30

//extern char* strdup(const char*);

typedef enum title {Ms, Mr} title_t;
struct person{
    title_t     title;
    char    *fname;
    char    *lname;
    char    *str;
    unsigned zip;
    char    *city;
};
typedef struct person person_t;

void add_person(person_t *persons, int i){
    char buf[LEN];
    int l;
    printf("Title: 0 for Ms. 1 for Mr.\n");
    do {
      scanf("%i", &persons[i].title);
        } while(getchar()!= '\n');
    printf("Firstname: ");
    fgets(buf, LEN, stdin); 
    l = strlen(buf);
    buf[l-1] = '\0'; 	// for carriage return
    persons[i].fname = strdup(buf);
    printf("Lastname: ");
    fgets(buf, LEN, stdin);
    l = strlen(buf);
    buf[l-1] = '\0';
    //persons[i].lname = malloc(l-1); // instead of the 3rd line
    //strcpy(persons[i].lname, buf);
    persons[i].lname = strdup(buf);
    printf("Street: ");
    fgets(buf, LEN, stdin);
    l = strlen(buf);
    buf[l-1] = '\0';
    persons[i].str = strdup(buf);
    printf("ZIP Code: ");
    do {
      scanf("%5u", &persons[i].zip);
   } while(getchar()!= '\n');
    printf("City: ");
    fgets(buf, LEN, stdin);
    l = strlen(buf);
    buf[l-1] = 0;
}

int find_slot(person_t persons[]){
    for(int i=0; i < MAX; i++){
        if(persons[i].zip == 0){
            return i;
        }
    }
            return -1;
}

void erase(person_t* persons, int i){
    if(persons[i].zip){
	persons[i].zip = 0;
	printf("Person %d is deleted.\n", i);
	free(persons[i].fname);
	free(persons[i].lname);
	free(persons[i].str);
    }
    else 
	printf("Person %d dosen't exist.\n", i);
}

void list(person_t persons[]){
    printf("No.\tTitle\tFirstname\tLastname\tStreet\tZIP\tCity\n\
---------------------------------------------------------------------\n");
    for(int i=0; i<MAX; i++){
        if(persons[i].zip !=0){
            printf("%i:\t", i);
            (persons[i].title==0 ? printf("Ms.\t"): printf("Mr.\t"));
            printf("%s\t%s\t%s\t%u\t%s\n", persons[i].fname, \
                   persons[i].lname,
persons[i].str, persons[i].zip, persons[i].city);
        }
    }
}

int main(){
    person_t persons[MAX];
    for(int i = 0; i<MAX; i++){
        persons[i].zip = 0;
    }
        int choice, i=0;
    do{
        printf("\nPlease choose an option:\n1 Add a person\n2 Delete a person\n3 List all persons\n4 Exit\n");
        scanf("%d", &choice);
        getchar();
	//int c;  while ((c=getchar())!='\n' && c != EOF);
        switch(choice){
            case 1:
                i = find_slot(persons);
                printf("i = %i\n", i);
                if(i == -1){
                    printf("No free slot.\n");
                    break;
                }
                else{
                    add_person(persons, i);
                }
                break;
            case 2:
                printf("Which number do you want to delete?\n");
                scanf("%d", &i);
                getchar();
                erase(persons, i);
                break;
            case 3: list(persons);
                break;
            case 4: 
		    while(persons[i].zip != 0){
			free(persons[i].fname);
			free(persons[i].lname);
			free(persons[i].str);
			free(persons[i++].city);
    	}
		    return 0;
        }
    }while(choice < 5);
    i = 0;
        return 0;
}
