/* Otazka: 1_9 Napíšte funkciu PosuvnaSuma(int *pole, int velk_pola), ktorá dostane ako vstup pole 
celých čísel a veľkosť poľa. Na výstupe vráti číslo, ktoré maximalizuje 
sumu hodnôt pole[i]*i, cez všetky možné posunutia. */

// Odpoved:

#include <stdio.h>

int ShiftSum(int *array, int array_size) {
    int max_sum = 0;
    int current_sum = 0;
    for (int i = 0; i < array_size; i++) {
        current_sum = 0;
        for (int j = 0; j < array_size; j++) {
            current_sum += array[(j+i)%array_size] * j;
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    return max_sum;
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int array_size = sizeof(array) / sizeof(array[0]);
    int result = ShiftSum(array, array_size);
    printf("Maximum sum: %d\n", result);
    return 0;
}
