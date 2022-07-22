#include <stdio.h>
#include <stdlib.h >

double harmonic(double a,double b)
{
    double average;
    average=2/(1.0/a+1.0/b);
    return average;
}

int main() {
    double num1,num2,har;
    char buffer[100]={0};
    char * pEnd;
    printf("Hello, World! Please enter two number.\n");
    gets(buffer);
    num1=strtod(buffer,&pEnd);
    num2=strtod(pEnd,NULL);
    har=harmonic(num1,num2);
    printf("The harmonic average for %.2f and %.2f is %.2f.",num1,num2,har);
    return 0;
}
