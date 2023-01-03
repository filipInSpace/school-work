
#include <stdio.h>
#define N 20  // maximum size of the square

int square[N][N];  // static array to store the elements of the square
int n;  // size of the square

int magically() {
  // check if the sum of the elements in each row is the same
  int row_sum = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += square[i][j];
    }
    if (i == 0) {
      row_sum = sum;
    } else if (sum != row_sum) {
      return 0;  // not magic
    }
  }

  // check if the sum of the elements in each column is the same
  int col_sum = 0;
  for (int j = 0; j < n; j++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += square[i][j];
    }
    if (j == 0) {
      col_sum = sum;
    } else if (sum != col_sum) {
      return 0;  // not magic
    }
  }

  // check if the sum of the elements in each diagonal is the same
  int diagonal1_sum = 0;
  int diagonal2_sum = 0;
  for (int i = 0; i < n; i++) {
    diagonal1_sum += square[i][i];
    diagonal2_sum += square[i][n-i-1];
  }
  if (diagonal1_sum != row_sum || diagonal2_sum != row_sum) {
    return 0;  // not magic
  }

  return 1;  // magic
}

int main() {
  printf("Enter the size of the square: ");
  scanf("%d", &n);

  if (n > N) {
    printf("Error: the size of the square should be less than or equal to %d\n", N);
    return 1;
  }

  printf("Enter the elements of the square:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &square[i][j]);
    }
  }

  int result = magically();
  if (result) {
    printf("The square is magic\n");
  } else {
    printf("The square is not magic\n");
  }

  return 0;
}
