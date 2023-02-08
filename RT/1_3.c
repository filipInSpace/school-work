/* Otazka: 1_3 Invertujte (zmeňte 1 na 0 a naopak) vo vstupnom čísle X od i-teho bitu n bitov (doľava). 
Index i je počítaný od 0. Premenná X je typu unsigned int, funkcia invertuj(...) ju dostane ako parameter, i a n sú celočíselné argumenty. 
Výstup funkcie je typu unsigned int. Funkciu implementujete pomocou bitových operácií.*/
// Odpoved:

#include <stdio.h>

unsigned int invert(unsigned int x, int i, int n);

int main() {
    unsigned int x;
    int i,n;
    printf("Enter an unsigned int: ");
    scanf("%u", &x);
    printf("Enter the bit location you want to start inverting from: ");
    scanf("%d", &i);
    printf("Enter the number of bits you want to invert: ");
    scanf("%d", &n);
    printf("The inverted number is: %u\n", invert(x, i, n));
    return 0;
}

unsigned int invert(unsigned int x, int i, int n) {
    unsigned int mask = (1 << n) - 1;
    mask = mask << i;
    x ^= mask;
    return x;
}
