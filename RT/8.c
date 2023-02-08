/* Otazka: 8. Napíšte procedúru nasledovnik(), ktorá pre každý prvok vstupného poľa vypíše 
prvý väčší prvok (písmeno), ktorý sa nachádza vpravo od neho (abecedne). 
Ak takýto prvok neexistuje, procedúra vypíše 'NaN'.*/

// Odpoved:

#include <stdio.h>

#define N 10

void follower(char arr[N]) {
    for (int i = 0; i < N; i++) {
        int j;
        for (j = i+1; j < N; j++) {
            if (arr[j] > arr[i]) {
                printf("The first larger letter after %c is %c\n", arr[i], arr[j]);
                break;
            }
        }
        if (j == N) {
            printf("NaN\n");
        }
    }
}

int main() {
    char arr[N] = {'c', 'b', 'a', 'd', 'g', 'f', 'k', 'm', 'l', 'f'};
    follower(arr);
    return 0;
}
