/* Otazka: 4. Napíšte procedúru strdelete(char *s, int i, int n), ktorá vymaže z reťazca s, od pozície i (počítaná od 0) n znakov.
Predpokladajte, že reťazec je dlhší ako n+i znakov. 
Reťazec s sa nesmie prealokovávať t.j. výsledný reťazec sa nachádza na tej istej adrese ako s. */

// Odpoved:

#include <stdio.h>
#include <string.h>

void strdelete(char *s, int i, int n) {
    int len = strlen(s); 
    for (int j = i; j <= len - n; j++) {
        s[j] = s[j + n]; 
    }
    s[len - n] = '\0'; 
}

int main() {
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);

    strdelete(str, 7, 5); 
    printf("Modified string: %s\n", str);
    return 0;
}
