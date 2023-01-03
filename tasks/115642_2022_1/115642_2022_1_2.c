/*pr02.c Nacitaj znak a vypis v jazyku C
autor: Filip Navrkal
datum: 26.09.2022
*/
#include <stdio.h>
 int main () {
	 char f;
		printf("napiste lubovolny znak:");
			f = getchar(); // caka na vstup lubovolneho znaku
		printf("vas znak:");
			putchar(f);    //znak vypise
return 0;
}

