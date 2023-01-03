#include <stdio.h>

int main(void) {
  // Open the file in read mode
  FILE* file = fopen("text.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Initialize a counter for the number of spaces
  int num_spaces = 0;

  // Read each character in the file
  char c;
  while ((c = fgetc(file)) != EOF) {
    // If the character is an 'x' or 'X', print a message
    if (c == 'x' || c == 'X') {
      printf("I read X\n");
    }
    // If the character is a 'y' or 'Y', print a message
    else if (c == 'y' || c == 'Y') {
      printf("I read Y\n");
    }
    // If the character is a '#', '$', or '&', print a message
    else if (c == '#' || c == '$' || c == '&') {
      printf("I read the control character\n");
    }
    // If the character is a space, increment the counter
    else if (c == ' ') {
      num_spaces++;
    }
    // If the character is a '*', print a message and break out of the loop
    else if (c == '*') {
      printf("End\n");
      break;
    }
  }

  // Print the number of spaces read
  printf("Number of spaces read: %d\n", num_spaces);

  // Close the file
  fclose(file);
  return 0;
}
