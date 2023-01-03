/*pr04.c druha mocnina v jazyku C
autor: Filip Navrkal
datum: 26.09.2022
*/
#include <stdio.h>
int main() {
	int zadcislo;
	printf("zadajte lubovolne cislo:");
	scanf_s("%d", &zadcislo); // caka na vstup
	printf("druha mocnina vaseho cisla je: %d\n", zadcislo * zadcislo); // vstup sa vynasobi sam sebou
	return 0; 
}