#include <stdio.h>
#include <stdbool.h>
#define MAX 256
#define PRI_AT 2.05
#define PRI_BE 1.15
#define PRI_CA 1.09//蔬菜售价
#define BASE1 6.5
#define BASE2 14
#define add_base 0.5//配送费各阶段标准
#define DisCount 0.95

void picture(void);
bool character(char);//验证输入符合要求
char getChoice(void);//获取符合要求的输入&显示菜单

int main()
{
    double fre_pack,price;
    double w_sum=0,p_sum=0;//计算总重量和总的蔬菜费用
    char need;
    char you_need[MAX];//获取每次输入选择的蔬菜内容
    double weight[MAX];//获取蔬菜对应重量
    need=getChoice();
    int count=0;
    while(need!='q')
    {
        you_need[count]=need;
        printf("Please enter the pounds you want to get:");
        scanf("%lf",&weight[count]);
        count++;
        need=getChoice();
    }
    for(int bill=0;bill<count;bill++)
    {
        switch (you_need[bill])
        {
            case 'a':price = PRI_AT;break;
            case 'b':price = PRI_BE;break;
            case 'c':price = PRI_CA;break;
            default:break;
        }
        p_sum += weight[bill] * price;//累计计算蔬菜费用
        w_sum += weight[bill];//累计计算蔬菜总重

    }
    picture();
    printf("Hello,here your bill:\n");
    picture();
    for(int n=0;n<count;n++)
    {
        switch(you_need[n])
        {
            case 'a':printf("Artichoke $2.05/pound %.2f\n",weight[n]);break;
            case 'b':printf("Beet      $1.15/pound %.2f\n",weight[n]);break;
            case 'c':printf("Carrot    $1.09/pound %.2f\n",weight[n]);break;
            default:break;
        }
    }
    if (p_sum == 100)
    {
        p_sum *= DisCount;
        printf("Congratulations!You got a $100 95%%discount!\n");//满100折扣
    }
    if (w_sum <= 5)
        fre_pack = BASE1;
    else if (w_sum <= 20)
        fre_pack = BASE2;
    else
        fre_pack = BASE2 + (w_sum - 20) * add_base;
    printf("You need to pay $%.2f for your %.2f pounds vegetables, "
           "$%.2f for your freight and package fee.\n",p_sum,w_sum,fre_pack);
    printf("So the final fee is $%.2f.\n"
           "Welcome to buy our vegetables, wish you a good day.",p_sum+fre_pack);
    return 0;
}

void picture(void)
{
    for(int n=0;n<80;n++)
        printf("*");
    printf("\n");
}

bool character(char n)
{
    if(n=='a'||n=='b'||n=='c'||n=='q')
        return true;
    else
        return false;
}

char getChoice(void)
{
    char choice;
    int input;
    do
    {
        fflush(stdin);
        picture();
        printf("Enter the character corresponding to the desired vegetables or action.\n");
        printf("a) Artichoke $2.05/pound     b) Beet $1.15/pound\n"
               "c) Carrot $1.09/pound        q) quit\n");
        picture();
        input=scanf("%c",&choice);
    }while(input!=1||!character(choice));
    return choice;
}
