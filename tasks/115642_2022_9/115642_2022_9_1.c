
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_NAMES 100

typedef struct {
  char name[MAX_NAME_LEN];
  int count;
} NameCount;

int main() {
  NameCount names[MAX_NAMES];
  int num_names = 0;
  char buffer[MAX_NAME_LEN];

  while (scanf("%s", buffer) == 1) {
    // skontroluje ci sa meno uz nachadza
    int found = 0;
    for (int i = 0; i < num_names; i++) {
      if (strcmp(names[i].name, buffer) == 0) {
        names[i].count++;
        found = 1;
        break;
      }
    }

    // ak nie je meno na liste tak ho prida
    if (!found) {
      strcpy(names[num_names].name, buffer);
      names[num_names].count = 1;
      num_names++;
    }
  }

  // najde meno ktoreho je najviac
  int max_count = 0;
  char most_frequent_name[MAX_NAME_LEN];
  for (int i = 0; i < num_names; i++) {
    if (names[i].count > max_count) {
      max_count = names[i].count;
      strcpy(most_frequent_name, names[i].name);
    }
  }

  printf("%s\n", most_frequent_name);

  return 0;
}
