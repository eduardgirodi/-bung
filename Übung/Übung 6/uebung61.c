#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10 //Maximale Anzahl Personen
#define LEN 30 //Pufferlaenge

typedef enum anrede {
    Herr,
    Frau,
    } anrede_t;

typedef struct person {
    anrede_t anrede;
    char *vorname;
    char *nachname;
    char *strasse;
    unsigned plz;
    char *ort;
} person_t;

void add_person(person_t *personen, int i) {
    char buffer[LEN];

    printf("Anrede (0 fuer Herr, 1 fuer Frau): ");
    scanf("%d%*c", &personen[i].anrede);    //%*c reads a char but ignores it. Important so scanf does not leave a \n in stdin

    printf("Vorname: ");
    fgets(buffer, LEN, stdin);
    buffer[strlen(buffer)-1] = '\0';    //replaces newline character
    personen[i].vorname = strdup(buffer);

    printf("Nachname: ");
    fgets(buffer, LEN, stdin);
    buffer[strlen(buffer)-1] = '\0';
    personen[i].nachname = strdup(buffer);

    printf("Strasse: ");
    fgets(buffer, LEN, stdin);
    buffer[strlen(buffer)-1] = '\0';
    personen[i].strasse = strdup(buffer);

    printf("PLZ: ");
    scanf("%u%*c", &personen[i].plz);

    printf("Ort: ");
    fgets(buffer, LEN, stdin);
    buffer[strlen(buffer)-1] = '\0';
    personen[i].ort = strdup(buffer);
}

void delete(person_t *personen, int i) {
    if(personen[i].plz != 0) {
        personen[i].plz = 0;
        printf("Eintrag mit ID %d wurde entfernt.\n", i);
        free(personen[i].vorname);
        free(personen[i].nachname);
        free(personen[i].strasse);
        free(personen[i].ort);
    } else {
        printf("Einen Eintrag mit ID %d gibt es nicht.\n", i);
    }
}

void list(person_t *personen) {
    printf("ID\tAnrede\tVorname\t\tNachname\tStrasse\t\tPLZ\tOrt\n------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<MAX; i++) {
        if(personen[i].plz != 0) {
            printf("%d\t", i);
            (personen[i].anrede == 0) ? printf("Herr\t") : printf("Frau\t");
            printf("%s\t\t%s\t\t%s\t%u\t\t%s\n", personen[i].vorname, personen[i].nachname, personen[i].strasse, personen[i].plz, personen[i].ort);
        }
    }
}

int freeSlot(person_t *personen) {
    for(int i=0; i<MAX; i++) {
        if(personen[i].plz==0) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char **argv) {
    person_t personen[MAX];
    for(int i=0; i<MAX; i++) {
        personen[i].plz = 0;
    }
    unsigned choice;
    do {
        printf("Bitte waehlen Sie:\n1: Anlegen einer neuen Person in die Datenbank\n2: Entfernen einer Person aus der Datenkbank\n3: Auflisten aller Eintraege\n4: Exit\n");
        scanf("%u%*c", &choice);
        switch(choice) {
            case 1:
                if(freeSlot(personen)==-1) {
                    printf("Es kann kein neuer Eintrag angelegt werden. Die Datenbank ist voll.\n");
                }
                else {
                    add_person(personen, freeSlot(personen));
                }
                break;
            case 2:
                printf("Welcher Eintrag soll entfernt werden? (ID): ");
                int i;
                scanf("%d%*c", &i);
                delete(personen, i);
                break;
            case 3:
                list(personen);
                break;
            case 4:
                for(int i=0; i<MAX; i++) {
                    if(personen[i].plz != 0) {
                        free(personen[i].vorname);
                        free(personen[i].nachname);
                        free(personen[i].strasse);
                        free(personen[i].ort);
                    }
                }
            return 0;
        }
    } while(choice<5 && choice>0);
    return 0;
}