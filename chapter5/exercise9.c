#include <stdio.h>

void Temperatures(double);

int main() {
    double tem;
    int input;
    printf("Please enter the number of temperature(fah)(q to quit):");
    input = scanf("%lf",&tem);
    while(input == 1)
    {
        Temperatures(tem);
        printf("Please enter the number of temperature(fah)(q to quit):");
        input = scanf("%lf",&tem);
    }
    printf("Done!");
    return 0;
}

void Temperatures(double fah)
{
    double cel,kel;
    const double c2k = 273.16;
    cel = 5.0/9.0*(fah-32.0);
    kel = cel+c2k;
    printf("For fah %.2f , cel is %.2f and kel is %.2f\n",fah,cel,kel);
}
