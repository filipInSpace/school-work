/*
    FIIT STU
    Author: Filip Navrkal
    Project #2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people { 
    long long int ID;
    char meno[30];
    char modul[5];
    char velicina[4];
    double hodnota;
    int cas;
    int datum;
    long long int datetime;
    struct people* next;
}PEOPLE;

PEOPLE* n(PEOPLE* head, int* pocet_zaznamov) {
    int pocitadlo_zaznamov = 0, i, riadok = 0;
    char c, cache[20];
    FILE* fr = NULL;
    if (fr == NULL) {
        if ((fr = fopen("dataloger_V2.txt", "r")) == NULL)   
            printf("Zaznamy neboli nacitane!\n");
    }
    if (head != NULL) {
        PEOPLE* free_variable;
        while (head != NULL) {
            free_variable = head;
            head = head->next;
            free(free_variable);
        }
    }
    rewind(fr);
    PEOPLE* zaznam = NULL;
    while (fgets(cache, sizeof(cache), fr) != NULL) { 
        if (pocitadlo_zaznamov == 0) {
            head = (PEOPLE*)malloc(sizeof(PEOPLE));
            fgets(cache, 13, fr);
            head->ID = atoll(cache);
            fgets(head->meno, sizeof(head->meno), fr);
            strtok(head->meno, "\n");
            fgets(head->modul, sizeof(head->modul), fr);
            strtok(head->modul, "\n");
            fgets(head->velicina, sizeof(head->velicina), fr);
            strtok(head->velicina, "\n");
            fgets(cache, 20, fr);
            head->hodnota = atof(cache);
            fgets(cache, 20, fr);
            head->cas = atoi(cache);
            fgets(cache, 20, fr);
            head->datum = atoi(cache);
            pocitadlo_zaznamov++;
            zaznam = head;
        }
        else {
            zaznam->next = (PEOPLE*)malloc(sizeof(PEOPLE));
            zaznam = zaznam->next;
            fgets(cache, 13, fr);
            zaznam->ID = atoll(cache);
            fgets(zaznam->meno, sizeof(zaznam->meno), fr);
            strtok(zaznam->meno, "\n");
            fgets(zaznam->modul, sizeof(zaznam->modul), fr);
            strtok(zaznam->modul, "\n");
            fgets(zaznam->velicina, sizeof(zaznam->velicina), fr);
            strtok(zaznam->velicina, "\n");
            fgets(cache, 20, fr);
            zaznam->hodnota = atof(cache);
            fgets(cache, 20, fr);
            zaznam->cas = atoi(cache);
            fgets(cache, 20, fr);
            zaznam->datum = atoi(cache);
            pocitadlo_zaznamov++;
        }
    }
    zaznam->next = NULL;
    *pocet_zaznamov = pocitadlo_zaznamov;
    printf("Nacitalo sa %d zaznamov\n", pocitadlo_zaznamov);
    return head;
}

void v(PEOPLE *head) {
    if (head != NULL) { 
        int poradie = 1;
        PEOPLE* zaznam = head;
        while (zaznam != NULL) {
            printf("%d\n", poradie);
            printf("ID cislo mer. osoby: %lld\n", zaznam->ID);
            printf("Meno osoby: %s\n", zaznam->meno);
            printf("Mer. modul: %s\n", zaznam->modul);
            printf("Typ mer. veliciny: %s\n", zaznam->velicina);
            printf("Hodnota: %f\n", zaznam->hodnota);
            printf("Cas merania: ");
            if (zaznam->cas < 1000)
                printf("0");
            printf("%d\n", zaznam->cas);
            printf("Datum: %d\n", zaznam->datum);
            zaznam = zaznam->next;
            poradie++;
        }
    }
}

PEOPLE* zmaz(PEOPLE* head, int pocet_zaznamov, int poradie) {
    PEOPLE* temp = head;
    PEOPLE* predosly = NULL;
    if (poradie == 1) { 
        temp = temp->next;
        free(head);
        return temp;
    }
    for (int i = 1; i < poradie; i++) { 
        predosly = temp;
        temp = temp->next;
    }
    if (poradie == pocet_zaznamov) { 
        free(temp);
        predosly->next = NULL;
        return head;
    }
    else{
        predosly->next = temp->next;      
        free(temp);
        return head;
    }
}

PEOPLE* z(PEOPLE* head, int* pocet_zaznamov) {
    long long int ID = 0;
    scanf("%lld", &ID);
    PEOPLE* zaznam = head;
    int poradie = 1;
    while (zaznam != NULL) {
        if (ID == zaznam->ID) {
            printf("Zaznam pre ID %lld pre modul %s bol vymazany.\n", zaznam->ID, zaznam->modul);
            head = zmaz(head, *pocet_zaznamov, poradie);
            (*pocet_zaznamov)--;
            poradie = 1;
            zaznam = head;
        }
        else {
            poradie++;
            zaznam = zaznam->next;
        }
    }
    return head;
}

PEOPLE* u(PEOPLE* head) {
    if (head != NULL) {
        PEOPLE* zaznam = head;
        while (zaznam != NULL) {
            zaznam->datetime = (long long int)zaznam->datum * 10000 + (long long int)zaznam->cas;
            zaznam = zaznam->next;
        }
        PEOPLE* zaciatok = NULL;
        PEOPLE* koniec = NULL;
        int swapped = 0;
        while (swapped) {
            swapped = 0;
            zaciatok = head;
            while (zaciatok->next != koniec) {
                if (zaciatok->datetime > zaciatok->next->datetime) {
                    
                    long long int ID;
                    char meno[30];
                    char modul[5];
                    char velicina[4];
                    double hodnota;
                    int cas;
                    int datum;
                    long long int datetime;
                    
                    ID = zaciatok->ID;
                    strncpy(meno, zaciatok->meno, 31);
                    strncpy(modul, zaciatok->modul, 5);
                    strncpy(velicina, zaciatok->velicina, 4);
                    hodnota = zaciatok->hodnota;
                    cas = zaciatok->cas;
                    datum = zaciatok->datum;
                    datetime = zaciatok->datetime;
                    
                    zaciatok->ID = zaciatok->next->ID;
                    strncpy(zaciatok->meno, zaciatok->next->meno, 31);
                    strncpy(zaciatok->modul, zaciatok->next->modul, 5);
                    strncpy(zaciatok->velicina, zaciatok->next->velicina, 4);
                    zaciatok->hodnota = zaciatok->next->hodnota;
                    zaciatok->cas = zaciatok->next->cas;
                    zaciatok->datum = zaciatok->next->datum;
                    zaciatok->datetime = zaciatok->next->datetime;
                    
                    strncpy(zaciatok->meno, meno, 31);
                    strncpy(zaciatok->modul, modul, 5);
                    strncpy(zaciatok->velicina, velicina, 4);
                    zaciatok->hodnota = hodnota;
                    zaciatok->cas = cas;
                    zaciatok->datum = datum;
                    zaciatok->datetime = datetime;
                }
                zaciatok = zaciatok->next;
            }
            koniec = zaciatok;
        }
    }
    return head;
}

PEOPLE* p(PEOPLE* head, int* pocet_zaznamov) {
    PEOPLE* novy = (PEOPLE*)malloc(sizeof(PEOPLE));
    PEOPLE* zaznam = head;
    int c1 = 0, poradie = 1;
    char cache[20];
    scanf("%d", &c1);
    fgets(cache, 13, stdin);
    fgets(cache, 13, stdin);
    novy->ID = atoll(cache);
    printf("%lld\n", novy->ID);
    fgets(novy->meno, 31, stdin);
    strtok(novy->meno, "\n");
    fgets(novy->modul, sizeof(novy->modul), stdin);
    strtok(novy->modul, "\n");
    fgets(novy->velicina, sizeof(novy->velicina), stdin);
    strtok(novy->velicina, "\n");
    fgets(cache, 20, stdin);
    novy->hodnota = atof(cache);
    fgets(cache, 20, stdin);
    novy->cas = atoi(cache);
    fgets(cache, 20, stdin);
    novy->datum = atoi(cache);
    if (c1 > *pocet_zaznamov) {    
        novy->next = NULL;
        if (head == NULL) {
            (*pocet_zaznamov)++;
            return novy;
        }
        else {
            while (zaznam->next != NULL) {
                zaznam = zaznam->next;
            }
            (*pocet_zaznamov)++;
            zaznam->next = novy;
            return head;
        }
    }
    else if (c1 == 1) {
        novy->next = head;
        (*pocet_zaznamov)++;
        return novy;
    }
    while ((zaznam->next != NULL) && (poradie < c1 - 1)) {
        zaznam = zaznam->next;
        poradie++;
    }
    (*pocet_zaznamov)++;
    novy->next = zaznam->next;
    zaznam->next = novy;
    return head;
}

void h(PEOPLE* head) {
    char modul[4];
    int poradie = 1;
    scanf("%s", modul);
    if (head != NULL) { 
        PEOPLE* zaznam = head;
        
        while (zaznam != NULL) {
            if (strstr(modul, zaznam->modul) != NULL) {
                printf("%d\n", poradie);
                printf("ID cislo mer. osoby: %lld\n", zaznam->ID);
                printf("Meno osoby: %s\n", zaznam->meno);
                printf("Mer. modul: %s\n", zaznam->modul);
                printf("Typ mer. veliciny: %s\n", zaznam->velicina);
                printf("Hodnota: %f\n", zaznam->hodnota);
                printf("Cas merania: ");
                if (zaznam->cas < 1000)
                    printf("0");
                printf("%d\n", zaznam->cas);
                printf("Datum: %d\n", zaznam->datum);
                poradie++;
            }
            zaznam = zaznam->next;
        }
    }
    if (poradie == 1)
        printf("Pre meraci modul %s niesu zaznamy\n", modul);
}

int main() {
    char vstup;
    int pocet_zaznamov = 0;
    PEOPLE* head = NULL;
    while (1) { 
        scanf("%c", &vstup);
        switch (vstup) {
            case 'n': {
                head = n(head, &pocet_zaznamov);
                break;
            }
            case 'v': {
                v(head);
                break;
            }
            case 'z': {
                head = z(head, &pocet_zaznamov);
                break;
            }
            case 'u': {
                head = u(head);
                break;
            }
            case 'p': {
                head = p(head, &pocet_zaznamov);
                break;
            }
            case 'h': {
                h(head);
                break;
            }            
            case 'k': {
                if (head != NULL) {
                    PEOPLE* free_variable;
                    while (head != NULL) {
                        free_variable = head;
                        head = head->next;
                        free(free_variable);
                    }
                }
                exit(0);
                break;
            }
        }
    }
    return 0;
}
