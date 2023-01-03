#include<stdio.h>

double tyzdenna_mzda(double mzda, double hod)
{
    return mzda * hod;
}

int main(){
    int n;
    double mzda, hod, celmzda;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &mzda, &hod);
        printf("Hod. mzda: %.2lf Euro/hod, hodin: %.2lf, spolu: %.2lf\n", mzda, hod, tyzdenna_mzda(mzda, hod));
        celmzda += tyzdenna_mzda(mzda, hod);
    }
    printf("Celkova mzda: %.2lf", celmzda); 
}
