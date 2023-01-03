/* *  pr2.8.c vypocet vyrazov v jazyku C
 *  autor: Filip Navrkal
 *  datum: 1.10.2022
*/
#include<stdio.h>
int main(){
    int a, b, c, d, e;                                          //deklaracia premennych
    float v1, v2;                     
    printf("napiste 5 celych cisel oddelenych medzerou: ");       
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);                //caka na vstup, nasledne ulozi vstup do premennej
    v1 = (e / --a * b++ / c++);                                 //ulozenie vysledku vyrazu do premennej 
    printf("%g\n", v1);                                         //vypisanie hodnoty danneho vyrazu 
    printf("napiste 5 celych cisel oddelenych medzerou: ");  
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);                //caka na vstup, nasledne ulozi vstup do premennej
    v2 = (a %= b = d = 1 + e / 2);                              //ulozenie vysledku vyrazu do premennej
    printf("%g", v2);                                           //vypisanie hodnoty danneho vyrazu
    return 0; 

}