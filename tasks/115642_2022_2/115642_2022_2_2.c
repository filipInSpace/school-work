/* *  pr2.2.c vypocet BMI v jazyku C
 *  autor: Filip Navrkal
 *  datum: 27.9.2022
*/
#include<stdio.h>
int main() {
	float v, h, bmi;			//zadeklarovanie premmennych
		printf("zadajte vasu vysku v m a hmotnost v kg oddelene medzerou: "); 
		scanf_s("%f %f", &v, &h);   						//program caka na input vysky a hmotnosti a ulozi ich do premennych
		bmi = h / (v * v);                                  //zadeklarovanie vzorca na bmi a ulozenie vysledku do bmi premennej
		printf("Vase BMI je: %g", bmi);                     // odvola sa ulozenu premennu bmi z predoslej operacie
	return 0; 
}