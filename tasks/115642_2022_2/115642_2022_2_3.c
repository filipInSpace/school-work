/* *  pr2.3.c zaokruhlovanie v jazyku C
 *  autor: Filip Navrkal
 *  datum: 27.9.2022
*/
#include<stdio.h>
int main() {
	float a;               				 //deklarovanie premennej 
	printf("Napiste realne cislo: "); 
	scanf_s("%f", &a);         				//caka na vstup realneho cisla a nasledne ho ulozi do premennej
	printf("%d %.0f", (int)a, a);         /*vypise celo ciselnu hodnotu zadaneho cisla pomocou %d a zmeny a na int   
	return 0;                                   a dalej vypise zaokruhlenu hodnotu zadaneho cisla  */
}