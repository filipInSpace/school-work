/* *  pr2.5.c zmena velkych pismen na male v jazyku C
 *  autor: Filip Navrkal
 *  datum: 1.10.2022
*/
#include<stdio.h>
int main(){
    int c1, c2;                                   //deklaracia premennych 
    printf("napiste dve velke pismena: ");
    scanf("%c %c", &c1, &c2);                       //caka na vstup, nasledne vstup je ulozeny do premennych 
            c1 = c1 - 'A' + 'a';                    //zmena vstupu velkeho pismenka na male 
            c2 = c2 - 'A' + 'a';
    printf("%c\n", c2);                                //vypisanie zmenenych pismenok v opacnom poradi 
    printf("%c\n", c1);
return 0;
}