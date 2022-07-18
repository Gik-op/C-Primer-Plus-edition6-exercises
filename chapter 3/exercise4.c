#include <stdio.h>

int main()
{
    float number;
    printf("Please input a floating-point value:");
    scanf("%f",&number);
    printf("fixed-point notation:%f\n",number);
    printf("exponential notation:%e\n",number);
    printf("p notation:%#x",number);//显然不支持十六进制
    return 0;
}
