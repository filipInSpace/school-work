#include<stdio.h>

int zisti_prvocislo(int cislo){

    if (cislo == 1) return(-1);

    for (int i = 2; i < cislo; i++)
    {
        if (cislo%i==0) return(-1);
    }
    return(1);
}
int main(){
int a, b, p; 
scanf("%d %d", &a, &b);
if (a > b)
{
            a = a + b;
            b = a - b;
            a = a - b;           
}
for (int i = a; i < b; i++){
    int c = zisti_prvocislo(i);
    if (c == 1){
        printf("%d ", i);
        p++;
    }
}
    if (p == 0){
        printf("Prvocislo neexistuje");
    }
return 0;
}

