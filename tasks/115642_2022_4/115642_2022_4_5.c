#include <stdio.h>

int digit_sum(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + digit_sum(n / 10);
}

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The digit sum of %d is %d.\n", n, digit_sum(n));
    return 0;
}