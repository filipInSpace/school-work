/* *  pr3.9
 *  autor: Filip Navrkal
 *  datum: 14.12.2022
*/

#include <stdio.h>

int main() {
  
  int x[] = {4, 7, 1, 3, 2, 5, 6};
  
  int y[7];

  // Pocitadlo pre pocet parnych cisel najdenych v x
  int n = 0;

  // prechod polom x
  for (int i = 0; i < 7; i++) {
    // kontrola parneho cisla
    if (x[i] % 2 == 0) {
      // ak je parna pridaj ho do y
      y[n] = x[i];
      n++;
    }
  }

  // vypic pola y
  for (int i = 0; i < n; i++) {
    printf("%d ", y[i]);
  }
  printf("\n");

  return 0;
}
