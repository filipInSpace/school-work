/* *  pr2.1.c aritmeticky priemer v jazyku C
 *  autor: Filip Navrkal
 *  datum: 27.9.2022
*/
#include<stdio.h>
int main() {
	float a, b, c, priemer;						//deklarovanie premennych 
	printf("napiste 3 realne cisla: ");
	scanf("%g %g %g", &a, &b, &c);			//caka na vstup
	priemer = (a + b + c) / 3;					//vzorec na vypocet priemeru
	printf("Priemer cisel %g %g %g je: %g", a, b, c, priemer);    // vypise primer zo zadanych cisel 
	return 0; 

}