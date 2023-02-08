/* Otazka: 1_2 Napíšte funkciu reksuma(int cislo), ktorá pomocou rekurzie vypočíta ciferný súčet 
celého čísla. Na vstupe je dané kladné celé číslo N. Návratová hodnota funkcie reprezentuje ciferný súčet čísla N */

//Odpoved:

#include <stdio.h>

int resum(int number);

int main() {
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    printf("The digit sum of %d is: %d\n", number, resum(number));
    return 0;
}

int resum(int number) {
    if (number == 0) {
        return 0;
    } else {
        return (number % 10 + resum(number / 10));
    }
}
