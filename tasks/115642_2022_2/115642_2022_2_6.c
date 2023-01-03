/* *  pr2.6.c porovnavanie v jazyku C
 *  autor: Filip Navrkal
 *  datum: 1.10.2022
*/
#include<stdio.h>
int main(){
    int c1, c2;                           //deklaracia premennych
    printf("napiste dve cele cisla ");
    scanf("%d %d", &c1, &c2);                //caka na vstup, nasledne zadane cisla ulozi do premennych 
    if (c1 > c2)                             //vytvorili sme podmienku v ktorej porovname dva vstupy a vypiseme jej vysledok
         printf("Cislo C1=%d je vacsie ako C2=%d", c1,c2); 
          else 
        printf("Cislo C1=%d je mensie ako C2=%d", c1,c2);
return 0;
}