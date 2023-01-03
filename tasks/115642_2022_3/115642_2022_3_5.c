/* *  pr3.5 nacitavanie pokial nie su splnene podmienky v jazyku C
 *  autor: Filip Navrkal
 *  datum: 10.10.2022
*/
#include <stdio.h>
int main(){
    printf("Zadajte cele nezaporne cislo \n"); 
    int N, i, faktorial;
    faktorial = 1;
    do {
        scanf("%d", &N); 
    }
    while (N < 0);
    for (i=1; i<= N; i++)
    {
        faktorial = faktorial*i;
    }
    printf("faktorial cisla %d je %d", N, faktorial);
    return 0;
}