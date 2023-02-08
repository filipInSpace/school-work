/* Otazka: 9. Pomocou bitových operácií zistite počet jednotkových bitov v premennej x. 
Premenná x je typu unsigned int, funkcia jednotky ju dostane ako parameter. */

// Odpoved: 

unsigned int count_unity_bits(unsigned int x) {
    unsigned int count = 0;
    while (x) {
        if (x & 1) {
            count++;
        }
        x >>= 1;
    }
    return count;
}

int main(){
  unsigned int x = 12;
  printf("The number of unity bits in %u is: %u\n", x, count_unity_bits(x));
  return 0;
}
