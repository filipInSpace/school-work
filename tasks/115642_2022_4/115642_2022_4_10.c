#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // Open the first file in read mode
  FILE* f1 = fopen("first.txt", "r");
  if (f1 == NULL) {
    printf("Error opening first file\n");
    return 1;
  }
  // Open the second file in read mode
  FILE* f2 = fopen("second.txt", "r");
  if (f2 == NULL) {
    printf("Error opening second file\n");
    return 1;
  }

  // Read the contents of the first file into a string
  fseek(f1, 0, SEEK_END);
  size_t len1 = ftell(f1);
  char* s1 = malloc(len1);
  fseek(f1, 0, SEEK_SET);
  fread(s1, len1, 1, f1);

  // Read the contents of the second file into a string
  fseek(f2, 0, SEEK_END);
  size_t len2 = ftell(f2);
  char* s2 = malloc(len2);
  fseek(f2, 0, SEEK_SET);
  fread(s2, len2, 1, f2);

  // Compare the lengths of the strings
  if (len1 != len2) {
    // If the strings are of different lengths, print a message indicating the difference in length
    printf("One of the files is longer by %d characters\n", abs(len1 - len2));
  } else {
    // Initialize a counter for the number of different characters
    size_t num_diff = 0;
    // Compare each character in the strings
    for (size_t i = 0; i < len1; i++) {
      // If the characters are not equal, increment the counter
      if (s1[i] != s2[i]) {
        num_diff++;
      }
    }
    // If the counter is zero, the files are identical
    if (num_diff == 0) {
      printf("Files are identical\n");
    }
    // If the counter is non-zero, print the number of different characters
    else {
      printf("Number of different characters: %d\n", num_diff);
    }
  }

  // Free the memory used by the strings
  free(s1);
  free(s2);
  // Close the files
  fclose(f1);
  fclose(f2);
  return 0;
}
