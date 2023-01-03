#include <stdio.h>

int main(void)
{
    double x;
    printf("Enter a number: ");
    scanf("%lf", &x);

    FILE *f = fopen("nasobky.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 1; i <= 10; i++)
    {
        fprintf(f, "%2d * %.2lf = %.2lf\n", i, x, i * x);
    }

    fclose(f);

    return 0;
}
