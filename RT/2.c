/* 2. Otazka: Napíšte funkciu minimum(), ktorá vráti minimálny 
prvok z prvkov, ktoré sa nachádzajú na oboch diagonálach štvorcovej matice 
NxN (premenná N je definovaná ako #define N 10). */

// Odpoved, pre jeden prvok z oboch diagonal:

#include<stdio.h>
#define N 10 

void minimum(int arr[N][N], int *min1, int *min2) {
    *min1 = arr[0][0];
    *min2 = arr[0][N-1]; 
    
    for (int i = 0; i < N; i++) {
        if (arr[i][i] < *min1) {
            *min1 = arr[i][i];
        }
    }

    for (int i = 0; i < N; i++) {
        if (arr[i][N - i - 1] < *min2) {
            *min2 = arr[i][N - i - 1];
        }
    }
}

int main() {
    int arr[N][N] = {
        {13, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
        {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
        {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        {1, 92, 93, 94, 95, 96, 97, 98, 99, 100}
    };
    int min1, min2;
    minimum(arr, &min1, &min2);
    printf("Minimal element from first diagonal: %d\n", min1);
    printf("Minimal element from second diagonal: %d\n", min2);
    return 0;
}
