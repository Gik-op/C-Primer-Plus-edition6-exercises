#include <stdio.h>

int main()
{
    int num1,num2,input1,input2;
    printf("This program computers moduli.\n"
           "Enter an integer to serve as the second operand:");
    input1 = scanf("%d",&num2);
    while(input1==0||num2==0)
    {
        printf("Wrong input!Enter again:");
        fflush(stdin);//处理缓冲区问题
        input1 = scanf("%d",&num2);
    }
    printf("Now enter the first operand:");
    input2 = scanf("%d",&num1);
    while(num1>0&&input2!=0)
    {
        printf("%d %% %d is %d.\n",num1,num2,num1%num2);
        printf("Enter next number for first operand(<=0 to quit):");
        input2 = scanf("%d",&num1);
    }
    printf("Good work!");
    return 0;
}
