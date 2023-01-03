
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int main()
{
  // Read the file name
  char file_name[100];
  printf("Enter the file name: ");
  scanf("%s", file_name);

  // Open the file
  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  // Count the occurrences of each letter in each line
  int line_count = 0;
  int letter_count[ALPHABET_SIZE];
  char line[100];
  while (fgets(line, sizeof(line), file) != NULL) {
    line_count++;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
      letter_count[i] = 0;
    }
    for (int i = 0; line[i] != '\0'; i++) {
      char c = tolower(line[i]);
      if (c >= 'a' && c <= 'z') {
        letter_count[c - 'a']++;
      }
    }
  }

  // Close the file
  fclose(file);

  // Print the histogram
  printf("  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
  for (int i = 1; i <= line_count; i++) {
    printf("%d ", i);
    for (int j = 0; j < ALPHABET_SIZE; j++) {
      printf("%d ", letter_count[j]);
    }
    printf("\n");
  }

  return 0;
}
