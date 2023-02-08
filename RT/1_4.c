/* Otazka 1_4  4. Napíšte funkciu strchar(char *s, char c), ktorá vráti ukazovateľ na posledný výskyt 
znaku c v reťazci s. Pri riešení nepoužívajte štandardnú funkciu na vyhľadávanie v reťazci. 
Ak sa v reťazci hľadaný znak nenachádza, funkcia vráti NULL*/
// Odpoved:

#include <stdio.h>

char* strchar(char *s, char c);

int main() {
    char s[100],c;
    printf("Enter a string: ");
    scanf("%s", s);
    printf("Enter a character to search for: ");
    scanf(" %c", &c);
    char* last_occurrence = strchar(s, c);
    if (last_occurrence == NULL) {
        printf("Character not found in string\n");
    } else {
        printf("The last occurrence of '%c' in '%s' is at index: %ld\n", c, s, last_occurrence - s);
    }
    return 0;
}

char* strchar(char *s, char c) {
    char* last_occurrence = NULL;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            last_occurrence = &s[i];
        }
    }
    return last_occurrence;
}
