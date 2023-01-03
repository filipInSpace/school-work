/* *  pr3.1.c prikaz swith() v jazyku C
 *  autor: Filip Navrkal
 *  datum: 4.10.2022
*/
#include<stdio.h>
int main(){
    int a, b, v; 
    char operacia; //deklaracia premennych 
    printf("Zadajte dve cele cisla a znak operacie: \n");
    scanf("%d %d %c", &a, &b, &operacia);                   //caka na vstup, nasledne vstupy ulozi do premennych 
    switch(operacia)                                                  //switch kontroluje aka hodnota sa nachadza v operacii a nasledne sa vykona case, ktoremu sa rovna zadana hodnota v operacii

    {                                                                            
        case '+': 
            v = a + b;                                                  //v pripade operacie rovnajucej sa + sa vykona scitanie a nasledne z daneho case vyjde
            printf("%d %c %d = %d\n", a, operacia, b, v); 
            break; 
        case '-':
            v = a - b;
            printf("%d %c %d = %d\n", a, operacia, b, v);
            break;
        case '*':
            v = a * b;
            printf("%d %c %d = %d\n", a, operacia, b, v);
            break;
        case '/':
            v = a / b; 
            printf("%d %c %d = %d\n", a, operacia, b, v);
            break; 
        default: 
            printf("Zle zadana volba\n");                      //ak nie je zadane ziadne znamienko aritmetickej operacie vypise toto

    }
    return 0; 
}