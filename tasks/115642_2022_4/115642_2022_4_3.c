
#include <stdio.h>

// Funkcia, ktorá obráti číslo
long reverse_number(long x) {
  long y = 0;

 
  while (x != 0) {
    // Získa poslednú číslicu x
    int last_digit = x % 10;

    // Vynásobí y 10 a pripočíta k nemu poslednú číslicu x
    y = y * 10 + last_digit;

    // Vydelí x 10, aby sa odstránila posledná číslica
    x /= 10;
  }

  // Vráti obrátené číslo
  return y;
}

int main() {
  // Číta čísla zo vstupu, kým sa nedosiahne koniec vstupu
  long x;
  while (scanf("%ld", &x) == 1) {
    // Vytvorí obrátené číslo x
    long y = reverse_number(x);

    //  Skontroluje, či x je palindróm
    if (x == y) {
      printf("Cislo %ld je palindrom\n", x);
    } else {
      printf("Cislo %ld nie je palindrom\n", x);
    }
  }

  return 0;
}