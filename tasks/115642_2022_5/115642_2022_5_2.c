/*uloha 5.2 v jazyku c
Autor: Filip Navrkal 
Datum: 23.10.2022*/

#include<stdio.h>

int *maximum (int*p_x, int*p_y){
    if(*p_x > *p_y){
    return p_x;}
    else{
    return p_y;}
}
int main()
{
    int x, y; 
    int *v;

    scanf("%d %d", &x, &y);

    v = maximum(&x, &y);
    printf("Cislo %d je vacie.\n", *v);

    
    return 0;
}