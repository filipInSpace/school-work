/* *  pr3.4 vypis mnozstvo riadkov v jazyku C
 *  autor: Filip Navrkal
 *  datum: 10.10.2022
*/
#include <stdio.h>
int main(){
    int N, i, n, u;
    u = 0;
    printf("Nacitaj cele cislo: \n");
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &n);
             if (n > 0 && n < 100){ 
                 u = u +1;
             }
    }
    printf("%d", u);
    return 0;
}