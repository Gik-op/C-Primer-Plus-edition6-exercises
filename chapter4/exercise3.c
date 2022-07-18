#include <stdio.h>

int main()
{
    double number;
    printf("Please enter a number:\n");
    scanf("%lf",&number);
    printf("The input is %f or %.1e\n",number,number);
    printf("The input is %+.3f or %.3E\n",number,number);
    int num =4;
    printf("The number is %03d or %-*d\n",num,5,num);//去掉“-”可以更清晰地显示%*d的作用
    return 0;
}
