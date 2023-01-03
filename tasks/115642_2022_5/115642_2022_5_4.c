/*uloha 5.1 v jazyku c
Autor: Filip Navrkal 
Datum: 23.10.2022*/

#include <stdio.h>

void vymen_ukazovatele(int**u1, int**u2){

        int *swap = *u1;
        *u1 = *u2; 
        *u2 = swap;
}

int main(){
    int a = 10, b = 14;
    int *p_a, *p_b;

    p_a = &a;
    p_b = &b;

        printf("pred vymenou: \n");

        printf("p_a: %p %d \n", (void *) p_a, *p_a);
        printf("p_b: %p %d \n", (void *) p_b, *p_b);

        printf("po vymene: \n");

        vymen_ukazovatele(&p_a, &p_b);

        printf("p_a: %p %d \n",(void *) p_a, *p_a);
        printf("p_b: %p %d \n",(void *) p_b, *p_b);


        
    return 0;

}