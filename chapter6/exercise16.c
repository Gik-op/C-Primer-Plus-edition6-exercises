#include <stdio.h>
#define MONEY 100
#define RATE1 0.1
#define RATE2 0.05

int main()
{
    double pro1,pro2,sum1,sum2;
    int year=0;
    sum1=sum2=100.0;
    while(sum1>=sum2)
    {
        pro1=MONEY*RATE1;
        sum1+=pro1;
        pro2=sum2*RATE2;
        sum2+=pro2;
        year++;
    }
    printf("Hello, %d years after they saved their money to the bank,\n"
           "Daphney get $%f, while Deirdre get $%f.\n",year,sum1,sum2);
    return 0;
}
