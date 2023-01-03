/* *  pr08.c objem kvadra v jazyku C
 *  autor: Filip Navrkal
 *  datum: 26.9.2022
*/
#include<stdio.h>
int main() {
	float a, b, c, V;                       //premenne
		printf("zadajte strany kvadra: ");
			scanf_s("%f%f%f", &a, &b, &c); //caka na vstup
	V = (a * b * c);                       // vzorec na objem kvadra
		printf("Objem: %.2f", V);          
	return 0;
}