/* *  pr3.10
 *  autor: Filip Navrkal
 *  datum: 14.12.2022
*/

#include<stdio.h>

int main(){
    char x[15];
        scanf("%s", &x);
        for (int b = 14; b >= 0; b--) {
        printf("%c", x[b]); 
    }
    return 0; 
}