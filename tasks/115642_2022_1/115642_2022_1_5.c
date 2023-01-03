/*pr05.c obvod kruhu v jazyku C
autor: Filip Navrkal
datum: 26.09.2022
*/
#include<stdio.h>
#include <stdlib.h>
int main() {
	double O, r, pi, vzorec;
	pi = 3.14;
	printf("zadajte polomer kruhu:\n");
	scanf_s("%lf", &r);
	vzorec = 2 * pi * r;
	printf("obvod kruhu je %f\n", vzorec);
	return 0;




}