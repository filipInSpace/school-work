/*projekt 1 v jazyku c
Autor: Filip Navrkal
Datum: 23. 10. 2022*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// spocita pocet cislic v cisle
int digit_count(int cislo) {
    int count = 0;
    while (cislo != 0) {
        cislo = cislo / 10;
        count++;
    }
    return count;
}

// spocita pocet cislic v cisle
int digit_countl(long long int cislo) {
    int count = 0;
    while (cislo != 0) {
        cislo = cislo / 10;
        count++;
    }
    return count;
}

// sortne prvky pola cas a podla neho aj prvky pola hodnota
void array_sort(int** cas, int** datum, double** hodnota, int dlzka) {
    int temp_cas;
    int temp_datum;
    int temp_merge;
    double temp_hodnota;
    int* merge = (int*)malloc(dlzka * sizeof(int));
    for (int i = 0; i < dlzka; i++) {
        *(merge + i) = *(*datum + i) * 10000 + *(*cas + i);
    }
    for (int i = 0; i < dlzka; i++) {
        for (int j = i + 1; j < dlzka; j++) {
            if (*(merge + i) > *(merge + j)) {
                temp_merge = *(merge + i);
                temp_cas = *(*cas + i);
                temp_datum = *(*datum + i);
                temp_hodnota = *(*hodnota + i);
                *(merge + i) = *(merge + j);
                *(*cas + i) = *(*cas + j);
                *(*datum + i) = *(*datum + j);
                *(*hodnota + i) = *(*hodnota + j);
                *(merge + j) = temp_merge;
                *(*cas + j) = temp_cas;
                *(*datum + j) = temp_datum;
                *(*hodnota + j) = temp_hodnota;
            }
        }
    }
    free(merge);
}

// sortne prvky pola cas a podla neho aj prvky pola hodnota
void array_sort2(long long int** merge, double** hodnota, int dlzka) {
    long long int temp_merge;
    double temp_hodnota;
    for (int i = 0; i < dlzka; i++) {
        for (int j = i + 1; j < dlzka; j++) {
            if (*(*merge + i) > *(*merge + j)) {
                temp_merge = *(*merge + i);
                temp_hodnota = *(*hodnota + i);
                *(*merge + i) = *(*merge + j);
                *(*hodnota + i) = *(*hodnota + j);
                *(*merge + j) = temp_merge;
                *(*hodnota + j) = temp_hodnota;
            }
        }
    }
}


int check_id(long long int id) {
    if (digit_countl(id) == 10 && id % 11 == 0)
        return 1;
    return 0;
}

int check_modul(char* modul) {
    if (strlen(modul) != 3 || modul[0] < 'A' || modul[0] > 'Z' || modul[1] < '0' || modul[1] > '9' || modul[2] < '0' || modul[2] > '9')
        return 0;
    return 1;
}

int check_velicina(char* velicina) {
    if ((velicina[0] == 'R' || velicina[0] == 'U' || velicina[0] == 'A'))
        if((velicina[1] == '1' || velicina[1] == '2' || velicina[1] == '4'))
            return 1;
    return 0;
}

int check_cas(char* cas) {
    if (cas[0] > '2' || cas[2] > '5' || (cas[0] == '2' && cas[1] > '3'))
        return 0;
    return 1;
}
int check_datum(char* datum) {
    if (datum[0] != '2' || datum[4] > '1' || datum[6] > '3' || (datum[6] == '3' && datum[7] > '1') || (datum[4] == '1' && datum[5] > '2'))
        return 0;
    return 1;
}

void c(FILE* fr) {
    if (fr == NULL)
        printf("Neotvoreny subor.\n");
    int correct = 1, riadok = 0, pocitadlo_riadkov = 0;
    char c;
    char cache[20];
    rewind(fr);
    while ((c = fgetc(fr)) != EOF) {     //cyklus, ktory nacitava vsetky znaky v subore
        if (c == '\n')   // spocitaju sa riadky
            pocitadlo_riadkov++;
    }
    rewind(fr);
    long long int id = 0;
    char modul[5];
    char velicina[4];
    char cas[6];
    int datum[10];
    for (riadok = 0; riadok <= pocitadlo_riadkov; riadok++) {
        switch (riadok % 7) {
            case 0: {
                fgets(cache, 13, fr);
                id = atoll(cache);
                if (!check_id(id)) {
                    printf("Nekorektne zadany vstup: %lld\n", id);
                    correct = 0;
                }
                break;
            }
            case 1: {
                fgets(modul, 5, fr);
                strtok(modul, "\n");
                if (!check_modul(modul)) {
                    printf("Nekorektne zadany vstup: %s\n", modul);
                    correct = 0;
                }
                break;
            }
            case 2: {
                fgets(velicina, 4, fr);
                strtok(velicina, "\n");
                if (!check_velicina(velicina)) {
                    printf("Nekorektne zadany vstup: %s\n", velicina);
                    correct = 0;
                }
                break;
            }
            case 3: {
                fgets(cache, 20, fr);
                break;
            }
            case 4: {
                fgets(cas, 20, fr);
                strtok(cas, "\n");
                if (!check_cas(cas)) {
                    printf("Nekorektne zadany vstup: %s\n", cas);
                    correct = 0;
                }
                break;
            }
            case 5: {
                fgets(datum, 20, fr);
                strtok(datum, "\n");
                if (!check_datum(datum)) {
                    printf("Nekorektne zadany vstup: %s\n", datum);
                    correct = 0;
                }
                break;
            }
            case 6: {
                fgets(cache, 20, fr);
                break;
            }
        }
    }
    if (correct)
        printf("Data su korektne.");
}

FILE* v(FILE* fr, int dynamic, int pocet_zaznamov, long long int* id_d, char** modul_d, char** velicina_d, double* hodnota_d, int* cas_d, int* datum_d) {
    long long int id;
    char modul[5];
    char velicina[4];
    double hodnota;
    int cas;
    int datum;
    char cache[20];
    int zaznam = 0;
    if (fr == NULL) {
        if ((fr = fopen("dataloger.txt", "r")) == NULL)   //subor sa nepodarilo otvorit 
            printf("Neotvoreny subor\n");
    }
    if (dynamic == 0) { // dynamicke polia este neboli vytvorene
        rewind(fr); // vrati smernik suboru na zaciatok
        while (fgets(cache, 13, fr) != NULL) {  // pokial nie sme na konci suboru
            id = atoll(cache);
            printf("ID cislo mer. osoby: %lld\n", id);

            fgets(modul, sizeof(modul), fr);
            printf("Mer. modul: %s", modul);

            fgets(velicina, sizeof(velicina), fr);
            printf("Typ mer. veliciny: %s", velicina);

            fgets(cache, sizeof(cache), fr);
            hodnota = atof(cache);
            printf("Hodnota: %f\n", hodnota);

            fgets(cache, sizeof(cache), fr);
            cas = atoi(cache);
            printf("Cas merania: ");
            // cas si ukladame do intu a v pripade, ze nie je stvormiestny na zaciatok doplnime nulu
            if (digit_count(cas) != 4)
                printf("0");
            printf("%d\n", cas);
            

            fgets(cache, sizeof(cache), fr);
            datum = atoi(cache);
            printf("Datum: %d\n", datum);

            fgets(cache, sizeof(cache), fr);
            printf("\n");
        }
    }
    else if (dynamic == 1) {    // vypisujeme udaje uz z dynamickych poli
        for (zaznam = 0; zaznam < pocet_zaznamov; zaznam++) {
            printf("ID cislo mer. osoby: %lld\n", *(id_d + zaznam));
            printf("Mer. modul: %s\n", *(modul_d + zaznam));
            printf("Typ mer. veliciny: %s\n", *(velicina_d + zaznam));
            printf("Hodnota merania: %f\n", *(hodnota_d + zaznam));
            printf("Cas merania: ");
            // cas si ukladame do intu a v pripade, ze nie je stvormiestny na zaciatok doplnime nulu
            if (digit_count(*(cas_d + zaznam)) != 4)
                printf("0");
            printf("%d\n", *(cas_d + zaznam));
            printf("Datum: %d\n", *(datum_d + zaznam));
            printf("\n");
        }
    }
    return fr;
}

int n(FILE *fr, int *dynamic, long long int **id, char ***modul, char ***velicina, double **hodnota, int **cas, int **datum){
    int pocitadlo_riadkov = 0, pocitadlo_zaznamov = 0, i, riadok = 0;
    char c, cache[20];
    if(fr == NULL){
        printf("Neotvoreny subor\n");
        return 0;
    }
    else {
        rewind(fr);
        while ((c = fgetc(fr)) != EOF) {     //cyklus, ktory nacitava vsetky znaky v subore
            if (c == '\n')   // spocitaju sa riadky
                pocitadlo_riadkov++;
        }
        pocitadlo_zaznamov = (pocitadlo_riadkov + 1) / 7;   // z poctu riadkov sa vyrata pocet zaznamov
        if (*dynamic == 1) {    // dynamicke polia uz boli vytvorene, uvolnime ich a nasledne vytvorime nanovo
            free(*id);
            *id = NULL;

            for (i = 0; i < pocitadlo_zaznamov; i++) {
                free(*(*modul + i));
            }
            free(*modul);
            *modul = NULL;
            
            for (i = 0; i < pocitadlo_zaznamov; i++) {
                free(*(*velicina + i));
            }
            free(*velicina);
            *velicina = NULL;

            free(*datum);
            *datum = NULL;
            free(*cas);
            *cas = NULL;
            free(*hodnota);
            *hodnota = NULL;
        }
        rewind(fr);
        *id = (long long int*)malloc(pocitadlo_zaznamov * sizeof(long long int));
        *modul = (char**)malloc(pocitadlo_zaznamov * sizeof(char*));
        for (i = 0; i < pocitadlo_zaznamov; i++) {
            *(*modul + i) = (char*)malloc(5 * sizeof(char));
        }
        *velicina = (char**)malloc(pocitadlo_zaznamov * sizeof(char*));
        for (i = 0; i < pocitadlo_zaznamov; i++) {
            *(*velicina + i) = (char*)malloc(50 * sizeof(char));
        }
        *hodnota = (double*)malloc(pocitadlo_zaznamov * sizeof(double));
        *datum = (int*)malloc(pocitadlo_zaznamov * sizeof(int));
        *cas = (int*)malloc(pocitadlo_zaznamov * sizeof(int));
        for (riadok = 0; riadok <= pocitadlo_riadkov; riadok++) {   // nacitame vsetky udaje do dynamickych poli
            switch (riadok % 7) {
                case 0: {
                    fgets(cache, 13, fr);
                    *(*id + (riadok / 7)) = atoll(cache);
                    break;
                }                                                               
                case 1: {
                    fgets(*(*modul + (riadok / 7)), 5, fr);
                    strtok(*(*modul + (riadok / 7)), "\n");
                    break;
                }
                case 2: {
                    fgets(*(*velicina + (riadok / 7)), 4, fr);
                    strtok(*(*velicina + (riadok / 7)), "\n");
                    break;
                }
                case 3: {
                    fgets(cache, 20, fr);
                    *(*hodnota + (riadok / 7)) = atof(cache);
                    break;
                }
                case 4: {
                    fgets(cache, 20, fr);
                    *(*cas + (riadok / 7)) = atoi(cache);
                    break;
                }
                case 5: {
                    fgets(cache, 20, fr);
                    *(*datum + (riadok / 7)) = atoi(cache);
                    break;
                }
                case 6: {
                    fgets(cache, 20, fr);
                    break;
                }
            }
        }
        *dynamic = 1;   // nastavime premennu, ze dynamicke polia uz boli vytvorene
        return pocitadlo_zaznamov;
    }
}

void o(FILE* fr, int dynamic, int pocet_zaznamov, char** modul_d, char** velicina_d, double* hodnota_d, int* cas_d, int* datum_d) {
    char c;
    char modul[4];
    char velicina[3];
    char cache[20];
    int* zoznam_casov = NULL;
    int* zoznam_datumov = NULL;
    double* zoznam_hodnot = NULL;
    int pocet = 0;
    int pocitadlo_riadkov = 0;
    int pocitadlo_zaznamov = 0;
    int zaznam;
    scanf("%s %s", modul, velicina);
    if (!dynamic) { // dynamicke polia este nevytvorene
        if (fr == NULL)
            printf("Neotvoreny subor.\n");
        rewind(fr);
        while ((c = fgetc(fr)) != EOF) {     //cyklus, ktory nacitava vsetky znaky v subore
            if (c == '\n')   // spocitaju sa riadky
                pocitadlo_riadkov++;
        }
        pocitadlo_zaznamov = (pocitadlo_riadkov + 1) / 7;   // z poctu riadkov sa vyrata pocet zaznamov
        rewind(fr);
        char modul_subor[5];
        char velicina_subor[4];
        int cas_subor;
        int datum_subor;
        double hodnota_subor;
        zoznam_casov = (int*)malloc(pocitadlo_zaznamov * sizeof(int));
        zoznam_datumov = (int*)malloc(pocitadlo_zaznamov * sizeof(int));
        zoznam_hodnot = (double*)malloc(pocitadlo_zaznamov * sizeof(double));
        for (zaznam = 0; zaznam < pocitadlo_zaznamov; zaznam++) {
            fgets(cache, 13, fr);
            fgets(modul_subor, 5, fr);
            strtok(modul_subor, "\n");
            fgets(velicina_subor, 4, fr);
            strtok(velicina_subor, "\n");
            fgets(cache, 20, fr);
            hodnota_subor = atof(cache);
            fgets(cache, 20, fr);
            cas_subor = atoi(cache);
            fgets(cache, 20, fr);
            datum_subor = atoi(cache);
            fgets(cache, 20, fr);
            if ((strstr(modul_subor, modul) != NULL) && (strstr(velicina_subor, velicina) != NULL)) {   // zistujeme, ktore zaznamy maju rovnake hodnoty ako hladane
                *(zoznam_casov + pocet) = cas_subor;
                *(zoznam_datumov + pocet) = datum_subor;
                *(zoznam_hodnot + pocet) = hodnota_subor;
                pocet++;
            }
        }
        array_sort(&zoznam_casov, &zoznam_datumov, &zoznam_hodnot, pocet);   // vytriedime polia podla casu
        for (int najdeny_zaznam = 0; najdeny_zaznam < pocet; najdeny_zaznam++) {    // vypiseme odpovedajuce polia
            printf("%s %s %d ", modul, velicina, *(zoznam_datumov + najdeny_zaznam));
            if (digit_count(*(zoznam_casov + najdeny_zaznam)) != 4)
                printf("0");
            printf("%d %f\n", *(zoznam_casov + najdeny_zaznam), *(zoznam_hodnot + najdeny_zaznam));
        }
    }
    else {  // dynamicke polia uz vytvorene
        zoznam_casov = (int*)malloc(pocitadlo_zaznamov * sizeof(int));
        zoznam_datumov = (int*)malloc(pocitadlo_zaznamov * sizeof(int));
        zoznam_hodnot = (double*)malloc(pocitadlo_zaznamov * sizeof(double));
        for (int zaznam = 0; zaznam < pocet_zaznamov; zaznam++) {
            if ((strstr(*(modul_d + zaznam), modul) != NULL) && (strstr(*(velicina_d + zaznam), velicina) != NULL)) {   // zistujeme, ktore zaznamy maju rovnake hodnoty ako hladane
                *(zoznam_casov + pocet) = *(cas_d + zaznam);
                *(zoznam_datumov + pocet) = *(datum_d + zaznam);
                *(zoznam_hodnot + pocet) = *(hodnota_d + zaznam);
                pocet++;
            }
        }
        array_sort(&zoznam_casov, &zoznam_datumov, &zoznam_hodnot, pocet);   // vytriedime polia podla casu
        for (int najdeny_zaznam = 0; najdeny_zaznam < pocet; najdeny_zaznam++) {    // vypiseme odpovedajuce polia
            printf("%s %s %d ", modul, velicina, *(zoznam_datumov + najdeny_zaznam));
            if (digit_count(*(zoznam_casov + najdeny_zaznam)) != 4)
                printf("0");
            printf("%d %f\n", *(zoznam_casov + najdeny_zaznam), *(zoznam_hodnot + najdeny_zaznam));
        }
    }
    free(zoznam_casov);
    free(zoznam_datumov);
    free(zoznam_hodnot);
}

void s(FILE* fr, int dynamic, int pocet_zaznamov, char** modul_d, char** velicina_d, double* hodnota_d, int* cas_d, int* datum_d) {
    char c;
    char modul[4];
    char velicina[3];
    char cache[20];
    long long int* zoznam_merged = NULL;
    double* zoznam_hodnot = NULL;
    int pocet = 0;
    int zaznam;
    scanf("%s %s", modul, velicina);
    if (!dynamic) { // dynamicke polia este nevytvorene
        printf("Polia nie su vytvorene.\n");
    }
    else {  // dynamicke polia uz vytvorene
        zoznam_merged = (long long int*)malloc(pocet_zaznamov * sizeof(long long int));
        zoznam_hodnot = (double*)malloc(pocet_zaznamov * sizeof(double));
        for (int zaznam = 0; zaznam < pocet_zaznamov; zaznam++) {
            if ((strstr(*(modul_d + zaznam), modul) != NULL) && (strstr(*(velicina_d + zaznam), velicina) != NULL)) {   // zistujeme, ktore zaznamy maju rovnake hodnoty ako hladane
                *(zoznam_merged + pocet) = (long long int)*(datum_d + zaznam) * 10000 + (long long int)*(cas_d + zaznam);
                *(zoznam_hodnot + pocet) = *(hodnota_d + zaznam);
                pocet++;
            }
        }
        array_sort2(&zoznam_merged, &zoznam_hodnot, pocet);   // vytriedime polia podla casu
        FILE* fr2;
        fr2 = fopen("vystup_S.txt", "w");
        if (pocet == 0) {
            printf("Pre dany vstup neexistuju zaznamy.\n");
        }
        else {
            for (zaznam = 0; zaznam < pocet; zaznam++) {
                fprintf(fr2, "%lld %f\n", *(zoznam_merged + zaznam), *(zoznam_hodnot + zaznam));    
            }
        }
        fclose(fr2);
    }
    free(zoznam_merged);
    free(zoznam_hodnot);
}

int z(FILE* fr, int pocet_zaznamov, int dynamic, long long int** id, char*** modul, char*** velicina, double** hodnota, int** cas, int** datum) {
    if (!dynamic)
        printf("Dynamicke polia neboli vytvorene.");
    long long int id_compare;
    int zmazanych = 0;
    int zaznam = 0;
    scanf("%lld", &id_compare); 
    for (zaznam = 0; zaznam < pocet_zaznamov; zaznam++) {
        if (*(*id + zaznam) == id_compare) {
            *(*id + zaznam) = NULL;
            pocet_zaznamov--;
            zmazanych++;
        }
    }
    printf("Vymazalo sa: %d zaznamov !\n", zmazanych);
    return pocet_zaznamov;
}


int main() {
    FILE* fr = NULL; //deklarujem premmennu pre pracu so suborom

    //premmenne, na ktorych bude alokovana pamat
    //nastavenie premmenych na NULL  
    char** modul = NULL, ** velicina = NULL, vstup;
    long long int *id = NULL;
    int *cas = NULL, *datum = NULL;
    int pocet_zaznamov = 0, dynamic = 0;
    double *hodnota = NULL;

    
    while (1) { //nekonecny cyklus 
        scanf("%c", &vstup);    
        switch (vstup) {
            case 'v': {
                fr = v(fr, dynamic, pocet_zaznamov, id, modul, velicina, hodnota, cas, datum);
                break;
            }
            case 'n': {
                pocet_zaznamov = n(fr, &dynamic, &id, &modul, &velicina, &hodnota, &cas, &datum);
                break;
            }
            case 'o': {
                o(fr, dynamic, pocet_zaznamov, modul, velicina, hodnota, cas, datum);
                break;
            }
            case 'c': {
                c(fr);
                break;
            }
            case 's': {
                s(fr, dynamic, pocet_zaznamov, modul, velicina, hodnota, cas, datum);
                break;
            }
            case 'h': {
                break;
            }
            case 'p': {
                break;
            }
            case 'z': {
                pocet_zaznamov = z(fr, pocet_zaznamov, dynamic, &id, &modul, &velicina, &hodnota, &cas, &datum);
                break;
            }
            case 'k':{
                if (dynamic) {     // dealokacia dynamickych poli po zadani k
                    for (int i = 0; i < pocet_zaznamov; i++) {
                        free(*(modul + i));
                        *(modul+ i) = NULL;               
                    }
                    free(modul);
                    modul = NULL;
                    free(id);
                    id = NULL;
                    for (int i = 0; i < pocet_zaznamov; i++) {
                        free(*(velicina + i));
                        *(velicina + i) = NULL;
                    }
                    free(velicina);
                    velicina = NULL;
                    free(cas);
                    cas = NULL;
                    free(datum);
                    datum = NULL;
                    free(hodnota);
                    hodnota = NULL;
                }
                if(fr != NULL){
                    fclose(fr);
                }
                exit(0);
            }
        }
    }
    
    return 0;
}