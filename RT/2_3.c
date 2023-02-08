/* Otazka: 3.	Napíšte procedúru binarny_histogram, ktorá vypíše počet jednotiek a núl čísla v jeho binárnej reprezentácii. 
 Číslo dostane procedúra ako vstup (argument je typu unsigned int).*/
 
// Odpoved:

#include <stdio.h>

void binary_histogram(unsigned int num) {
    int one_count = 0;
    int zero_count = 0;

    while (num) {
        if (num & 1) {
            one_count++;
        } else {
            zero_count++;
        }
        num >>= 1;
    }
    printf("Ones: %d\nZeroes: %d\n", one_count, zero_count);
}

int main() {
    unsigned int num = 10;
    binary_histogram(num);
    return 0;
}


