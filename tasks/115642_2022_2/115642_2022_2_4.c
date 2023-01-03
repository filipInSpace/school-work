/* *  pr2.4.c zmena malych pismen na velke a vypisanie ich ASCII hodnoty v jazyku C
 *  autor: Filip Navrkal
 *  datum: 1.10.2022
*/
#include<stdio.h>
int main(){
    int c1, c2;                              //deklaracia premennych
    printf("napiste dve male pismena: ");          
    scanf("%c %c", &c1, &c2);                //caka na vstup pouzivatela a nasledne jeho vstupy ulozi do premennych 
                                                
            c1 = c1 + 'A' - 'a';               //male pismenka zmeni na velke
            c2 = c2 + 'A' - 'a';

    printf("%c %d\n", c1, c1);               //vypise velke pismenko, ktore je ulozene v premmenej a zaroven jeho ASCII hodnotu 
    printf("%c %d\n", c2, c2);
return 0;
}