#include <stdio.h>

int main(void) {
  // Declare variables to store the input character and the read character
  char input, read_char;

  // Read a character from standard input (keyboard)
  scanf("%c", &input);

  // Open the character.txt file for reading
  FILE *fp = fopen("character.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Open the novy.txt file for writing if the input character is 's',
  // otherwise open it for reading
  FILE *output_fp;
  if (input == 's') {
    output_fp = fopen("novy.txt", "w");
  } else {
    output_fp = stdout;
  }

  // Read characters from the character.txt file and write them to the
  // appropriate output (either novy.txt or standard output)
  while ((read_char = fgetc(fp)) != EOF) {
    fputc(read_char, output_fp);
  }

  // Close the files
  fclose(fp);
  fclose(output_fp);

  return 0;
}