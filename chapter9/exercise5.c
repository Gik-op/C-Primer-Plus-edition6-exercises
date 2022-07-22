#include <stdio.h>

void large_of(double* a,double* b)
{
    if(*a>*b)
        *b=*a;
    else
        *a=*b;
}

int main()
{
    double num1,num2;
    printf("Hello, please enter two number:\n");
    scanf("%lf %lf",&num1,&num2);
    printf("num1 = %.2f num2=%.2f.\n",num1,num2);
    large_of(&num1,&num2);
    printf("num1 = %.2f num2=%.2f.\n",num1,num2);
    return 0;
}