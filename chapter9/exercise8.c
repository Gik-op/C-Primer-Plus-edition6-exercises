#include <stdio.h>

double power(double,int);

int main()
{
    double num1,pow;
    int num2;
    printf("Hello, please enter the number and the power number:\n");
    scanf("%lf %d",&num1,&num2);
    pow=power(num1,num2);
    printf("%f^%d = %f.\n",num1,num2,pow);
    return 0;
}
double power(double num,int pow)
{
    double result=1;
    int flag;
    if(pow<0)
    {
        pow*=-1;
        flag=1;
    }
    else
        flag=0;
    for(int n=0;n<pow;n++)
        result*=num;//确保任何数零次幂为1
    if(num==0)
    {
        result=1;//确保零的任何次幂为1
        if(pow==0)
            printf("Zero to the 0th power is undefined.\n");//对0的0次幂的处理
    }
    if(flag==1)
        result=1.0/result;
    return result;
}
