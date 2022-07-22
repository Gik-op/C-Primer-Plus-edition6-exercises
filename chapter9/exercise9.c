#include <stdio.h>
#include <stdlib.h>

double power(double,int);

int main()
{
    double num1,pow;
    int num2;
    printf("Hello, please enter the number and the power number:\n");
    while(scanf("%lf %d",&num1,&num2)==2)
    {
        pow=power(num1,num2);
        printf("%f^%d = %f.\n",num1,num2,pow);
        printf("Hello, please enter the number and the power number:\n");
    }
    printf("Bye.\n");
    return 0;
}

double power(double num,int pow)
{
    double result;
    if(pow>0)
        result=num*power(num,pow-1);
    else if(pow<0)
        result=num*power(num,abs(pow)-1);
    else
        result=1;//满足0的任意次幂均为0
    if(num==0&&pow==0)
        printf("Zero to the 0th power is undefined.\n");
    if(pow<0)
        result=1.0/result;
    return result;
}