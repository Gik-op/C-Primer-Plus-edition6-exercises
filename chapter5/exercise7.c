#include <stdio.h>

double cube(double);

int main()
{
    double num,final;
    int input;
    printf("Please input the number:\n");
    input=scanf("%lf",&num);
    while(input==1)
    {
        final=cube(num);
        printf("The cube of the number is %.2f.\n",final);
        printf("Please input the number(q to quit):\n");
        input=scanf("%lf",&num);
    }
    printf("Well done!");
    return 0;
}

double cube(double n)
{
    double cu;
    cu = n*n*n;
    return cu;
}
