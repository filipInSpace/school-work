/* *  pr3.6 delitelnost tromi v jazyku C
 *  autor: Filip Navrkal
 *  datum: 10.10.2022
*/
#include <stdio.h>
int main(){
    int f, g, i;
    scanf("%d %d", &f, &g);
        if (f > g){
            f = f + g;
            g = f - g;
            f = f - g;
        }
for (i = f + 1; i < g; i++){
    if(i%3==0)
    {
printf("%d ", i);
    }
}
return 0;
}
