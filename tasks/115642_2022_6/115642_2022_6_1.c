
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int* allocate_1D_pole(int m);
void vypis_1D_pole(int* pole, int m);
int maximum_pos(int* pole, int m);
int minimum_pos(int* pole, int m);

int main()
{
  // nacitanie rozmerov pola
  int m;
  printf("zadajte rozmery pola: ");
  scanf("%d", &m);

  // alokovanie pamati pre pole
  int* field = allocate_1D_pole(m);
  if (field == NULL) {
    printf("nepodarilo sa alokovat pamat pre pole.\n");
    return 1;
  }

  // napl pole znakmi z klavesnice
  printf("zadajte znaky: ");
  for (int i = 0; i < m; i++) {
    scanf("%d", &field[i]);
  }

  // vypis pola
  vypis_1D_pole(field, m);

  // najdenie maxima a minima 
  int max_pos = maximum_pos(field, m);
  int min_pos = minimum_pos(field, m);
  printf("Maximalna hodnota je %d na pozicii %d\n", field[max_pos], max_pos);
  printf("Minimalna hodnota je %d na pozicii %d\n", field[min_pos], min_pos);

  // uvolni pamat
  free(field);

  return 0;
}

// alokovanie pamate pre 1D pole velkosti m
int* allocate_1D_pole(int m)
{
  int* pole = malloc(m * sizeof(int));
  return pole;
}

// vypisanie pola
void vypis_1D_pole(int* pole, int m)
{
  for (int i = 0; i < m; i++) {
    printf("%d ", pole[i]);
  }
  printf("\n");
}

// najde poziciu maximalnej hodnoty
int maximum_pos(int* pole, int m)
{
  int max_pos = 0;
  for (int i = 1; i < m; i++) {
    if (pole[i] > pole[max_pos]) {
      max_pos = i;
    }
  }
  return max_pos;
}

// najde poziciu minimalnej hodnoty
int minimum_pos(int* pole, int m)
{
  int min_pos = 0;
  for (int i = 1; i < m; i++) {
    if (pole[i] < pole[min_pos]) {
      min_pos = i;
    }
  }
  return min_pos;
}
