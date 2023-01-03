/* *  pr3.8 vykreslenie hviezdicky v jazyku C
 *  autor: Filip Navrkal
 *  datum: 16.12.2022
*/

#include <stdio.h>

int main() {
  // input hodnoty N
  int N;
  scanf("%d", &N);

  // Skontroluje, ci je N podmienka je platna
  if (N < 1 || N > 15 || N % 2 == 0) {
    printf("Bad input");
    return 1;
  }

  // Prechod radmi hviezdicky
  for (int i = 0; i < N; i++) {
    // prechod stlpcami
    for (int j = 0; j < N; j++) {
      // Skontroluje, ci je aktualna poloha na jednej z uhlopriecok alebo v strede hviezdy
      if ((i == j || i == N / 2 || j == N / 2) || (i + j == N - 1)) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}
