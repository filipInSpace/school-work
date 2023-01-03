#include <stdio.h>

int main(void)
{
    double sum = 0;

    FILE *f = fopen("cisla.txt", "r");
    if (f == NULL)
    {
        printf("The file does not exist: cisla.txt.\n");
        return 1;
    }

    double x;
    while (fscanf(f, "%lf", &x) == 1)
    {
        printf("%.2lf\n", x);
        sum += x;
    }

    printf("Sum: %.2lf\n", sum);

    fclose(f);

    return 0;
}
