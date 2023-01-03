/* *  pr3.2.c  v jazyku C
 *  autor: Filip Navrkal
 *  datum: 7.10.2022
*/
#include<stdio.h>
int main(){
    int N, k;
    float r, max, min; 
    printf("napiste cele cislo: \n");
    scanf("%d", &N);
    for (k = 1; k <= N; k++)
       {
           scanf("%f\n", &r);
              if (k == 1)
              {
                     max = r;
                     min = r;
              }
         if (r > max) max = r;
         if (r < min) min = r; 
       }  
printf("Maximum: %f\n", max);
printf("Minimum: %f\n", min);
       
return 0;
}

