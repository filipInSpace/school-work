/* *  pr3.3. postupnost c  v jazyku C
 *  autor: Filip Navrkal
 *  datum: 7.10.2022
*/
#include<stdio.h>

int main(){

    int N, n, i, n2, podmienka;
    printf("nacitajte cele cislo: \n");
    scanf("%d\n", &N);
    
    podmienka = 1;

    for (i = 1; i <= N; i++)
    {
        scanf("%d", &n);
        
        if (i == 1){
            if(n > 10 || n < 0)
            podmienka = 0;
        }
        else {
           if (n > 2*n2 || n < n2/2)
            podmienka =  0;
        }
        n2 = n;
    }
        if (podmienka == 1)
            printf("Postupnost je spravna\n");
            else 
            printf("Postupnost nie je spravna\n");
    
    

return 0;
}