
#include<stdio.h>

int rfunkcia (int N){
  int vysledok = 0;
  if(N > 0)
    {
        if(N % 2 == 1)
        {
        int vysledok = N + rfunkcia(N-1);
        return vysledok;  
        }

        if(N % 2 == 0)
        {
        int vysledok = rfunkcia(N-1);
        return vysledok;    
        }
        
    }
return vysledok;     
   }

int main(){
    int N; 
    scanf("%d", &N);
printf("%d", rfunkcia(N));
return 0;
}