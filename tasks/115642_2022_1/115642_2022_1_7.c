/*pr07.c dan v jazyku C
autor: Filip Navrkal
datum: 26.09.2022
*/
#include<stdio.h>
int main() {
	int cislo;
	float vypocet;

	printf("zadajte lubovolne cislo: ");
	scanf_s("%d", &cislo);

	vypocet = (float) cislo / 100 * 20 + cislo; 
	printf("cena bez dane: %d\n", cislo);
	printf("predajna cena s danou 20%% : %.1f", vypocet);
	return 0; 
}