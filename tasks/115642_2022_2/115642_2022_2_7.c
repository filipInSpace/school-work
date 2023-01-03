/* *  pr2.7.c nacitanie cisel a matematickej operacie v jazyku C
 *  autor: Filip Navrkal
 *  datum: 1.10.2022
*/
#include<stdio.h>
int main(){
    int a, b;                            //deklaracia premennych
    char operacia;
    printf("Napiste dve cisla a znak matematicke operacie: \n");
    scanf("%d %d %c", &a, &b, &operacia);           //nacita vstupy a nasledne ich v poradi ulozi, cisla ako int a mat. operaciu ako char
    if (operacia=='*')                              //pomocou podmienky if vypiseme taku matematicku operaciu ktoru zadal pouzivatel 
            {
                operacia = a * b;
        printf("%d * %d = %d", a, b, operacia);
            }
    else if (operacia=='/')
        {
            operacia = a / b;
        printf("%d / %d = %d", a, b, operacia);
        }
    else if (operacia=='+')
        {
            operacia = a + b;
        printf("%d + %d = %d", a, b, operacia);
        }
    else if (operacia=='-')
    {
        operacia = a - b;
        printf("%d - %d = %d", a, b, operacia);
    }
return 0;
}


