
/*uloha 5.1 v jazyku c
Autor: Filip Navrkal 
Datum: 23.10.2022*/

#include<stdio.h>

double nacitaj (double *a, double *b){
    return scanf("%lf %lf", a, b); 
}
double vypocitaj (double a, double b, double *O, double *S){
    *O = 2*( a + b );
    *S = a*b;
}

int main(){
    double a, b, O, S;

    nacitaj(&a, &b);

    vypocitaj( a, b, &O, &S);

    printf("Obsah: %.3lf\n", S);
    printf("Obvod: %.3lf\n", O);


    return 0;
}