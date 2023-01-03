/* *  pr03.c sucet sucin v jazyku C
 *  autor: Filip Navrkal
 *  datum: 26.9.2022
*/
#include<stdio.h>
int main() {
	
	int cislo1, cislo2;
	int sucet, sucin;
	
	printf("napiste prve cislo :"); //zadavanie cisel
	scanf_s("%d", &cislo1);
	printf("napiste druhe cislo:");
	scanf_s("%d", &cislo2);

	sucet = cislo1 + cislo2;         //vzorce na vypocet
	sucin = cislo1 * cislo2;

	printf("sucet danych cisel je: %d\n", sucet);   //vypise operaciu so zadanym cislom
	printf("sucin danych cisel je: %d\n", sucin);

	return 0; 


}