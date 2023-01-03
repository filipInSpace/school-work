/* *  pr3.7 vypis N riadkov v jazyku C
 *  autor: Filip Navrkal
 *  datum: 10.10.2022
*/
#include<stdio.h>
int main(){
    int N, i, j;
    
    scanf("%d", &N);
    if (N < 1 || N > 15) {
        printf("Cislo nie je z daneho intervalu");
    }
    else {
        for (int j = 1; j <= N; j++){
            
            printf("%d: ", N);
            for (int i = N; N >= 1; N=N-1)
            {
                 printf("%d ", N);
             }
        printf("\n");
        }
    }
 return 0;        
}


    