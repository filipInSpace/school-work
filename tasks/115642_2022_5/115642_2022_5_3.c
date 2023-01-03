/*uloha 5.3 v jazyku c
Autor: Filip Navrkal 
Datum: 23.10.2022*/

#include <stdio.h>
#include <math.h>

double kvadraticka_rovnica(double a, double b, double c, double *koren1, double *koren2){
    double D = b*b - 4*a*c;   //deklaracia novej premennej, ktora reprezentuje Diskriminant a vzorec na vypocet diskriminantu 

    if(D > 0){
        *koren1 = (-b + sqrt(D)) / (2 * a);
        *koren2 = (-b - sqrt(D)) / (2 * a);
        return 2;
    }
    
    else if (D == 0){
         *koren1 = -b / (2 * a);
        return 1;
    }

    if (D < 0){
        return 0; 
    }
    
          

}

int main(){

    int pocetK;

    double a, b, c, koren1, koren2;

    scanf("%lf %lf %lf", &a, &b, &c);

    pocetK = kvadraticka_rovnica(a, b, c, &koren1, &koren2);

    printf("Pocet korenov kvadratickej rovnice je: %d\n", pocetK);
    printf("Prvy koren ma hodnotu: %.5lf\n", koren1);
    printf("Druhy koren ma hodnotu: %.5lf\n", koren2);
    
    
    return 0;
}