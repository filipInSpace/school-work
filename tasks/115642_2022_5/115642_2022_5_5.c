/*uloha 5.5 v jazyku c
Autor: Filip Navrkal 
Datum: 23.10.2022*/

#include <stdio.h>

int delitele(int x[], int pocetx, int y[], int k) //predpis funkcie
{
    int i, j =0;


    for (i = 0; i < pocetx; i++)

        if (x[i] != 0 && k % x[i]==0){
            y[j] = x[i];
            j++;
        }
        return j;        
}

int main()
{
    int i;
    int x[10] = {4, 7, 10, 2, 3, 9, 6, 5, 8, 12};
    int pocetx = 10; 
    int y[10];

    int pocety = delitele(x, pocetx, y, 24); 

    printf("pocet y: %d\ny:{", pocety);


    for (i = 0; i < pocety; i++){
        if(i > 0)
        printf(", ");
        printf("%d", y[i]);
    }
    printf("}\n");
    return 0; 
}
