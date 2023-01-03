
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int** allocate_2D_pole(int n, int m);
void vypis_2D_pole(int** pole, int n, int m);

int main()
{
  // Read the dimensions of the field
  int n, m;
  printf("Enter the dimensions of the field: ");
  scanf("%d%d", &n, &m);

  // Allocate memory for the field
  int** field = allocate_2D_pole(n, m);
  if (field == NULL) {
    printf("Error allocating memory for the field.\n");
    return 1;
  }

  // Fill the field with numbers from the keyboard
  printf("Enter the values for the field: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &field[i][j]);
    }
  }

  // Render the field to the console
  vypis_2D_pole(field, n, m);

  // Free the memory
  for (int i = 0; i < n; i++) {
    free(field[i]);
  }
  free(field);

  return 0;
}

// Allocates memory for a 2D array of size n x m
int** allocate_2D_pole(int n, int m)
{
  int** pole = malloc(n * sizeof(int*));
  if (pole == NULL) {
    return NULL;
  }
  for (int i = 0; i < n; i++) {
    pole[i] = malloc(m * sizeof(int));
    if (pole[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(pole[j]);
      }
      free(pole);
      return NULL;
    }
  }
  return pole;
}

// Renders a 2D array to the console
void vypis_2D_pole(int** pole, int n, int m)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", pole[i][j]);
    }
    printf("\n");
  }
}
