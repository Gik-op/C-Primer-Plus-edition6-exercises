#include <stdio.h>

void large_of(double* a,double* b,double* c)
{
    double temp;
    if(*a>*b)
    {
        temp=*a;
        *a=*b;
        *b=temp;
    }
    if(*b>*c)
    {
        temp=*b;
        *b=*c;
        *c=temp;
    }
    if(*a>*b)
    {
        temp=*a;
        *a=*b;
        *b=temp;
    }
}

int main()
{
    double num1,num2,num3;
    printf("Hello, please enter three number:\n");
    scanf("%lf %lf %lf",&num1,&num2,&num3);
    printf("num1 = %.2f num2=%.2f num3=%.2f.\n",num1,num2,num3);
    large_of(&num1,&num2,&num3);
    printf("num1 = %.2f num2=%.2f num3=%.2f.\n",num1,num2,num3);
    return 0;
}
