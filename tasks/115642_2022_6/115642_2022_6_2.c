
#include <stdio.h>
#include <stdlib.h>

int main()
{
  // nacita pocet znakov
  int n;
  printf("zadajte pocet znakov: ");
  scanf("%d", &n);

  // alokovanie pamati pre znaky
  char* characters = malloc(n * sizeof(char));
  if (characters == NULL) {
    printf("Nepodarilo sa alokovat pamat\n");
    return 1;
  }

  // nacita znaky z inputu pouzivatela
  printf("zadaj znaky: ");
  for (int i = 0; i < n; i++) {
    scanf(" %c", &characters[i]);
  }

  // vvypise dany pocet znakov odzadu
  printf("zadane znaky odzadu: ");
  for (char* p = characters + n - 1; p >= characters; p--) {
    printf("%c", *p);
  }
  printf("\n");

  // uvolni pamat
  free(characters);

  return 0;
}
