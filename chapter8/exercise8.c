#include <stdio.h>

char getRight(void);
float getNum(int rank,char choose);

int main()
{
    char choice;
    float number1,number2;
    while(1)
    {
        printf("Enter the operation of your choice:\n");
        printf("a.add           s.subtract\n");
        printf("m.multiply      d.divide\nq.quit\n");
        choice=getRight();
        if(choice=='q')
            break;
        printf("Enter first number:");
        number1=getNum(1,choice);
        printf("Enter second number:");
        number2= getNum(2,choice);
        switch(choice)
        {
            case 'a':printf("%.2f + %.2f = %.2f.\n",number1,number2,number1+number2);break;
            case 's':printf("%.2f - %.2f = %.2f.\n",number1,number2,number1-number2);break;
            case 'm':printf("%.2f * %.2f = %.2f.\n",number1,number2,number1*number2);break;
            case 'd':printf("%.2f / %.2f = %.2f.\n",number1,number2,number1/number2);break;
        }
    }
    printf("Bye.");
    getchar();
    return 0;
}

char getRight(void)
{
    char ch;
    int input;
    input=scanf("%c",&ch);//scanf()读取字符的时候，会读取回车，因此后面读取数字时要清空缓冲区
    while(input!=1||(ch!='a'&&ch!='s'&&ch!='m'&&ch!='d'&&ch!='q'))
    {
        fflush(stdin);
        printf("Wrong input!\nEnter again!\n");
        input=scanf("%c",&ch);
    }
    fflush(stdin);
    return ch;
}

float getNum(int rank,char choose)
{
    char error;
    float num;
    if(rank==2&&choose=='d')
    {
        while(scanf("%f",&num)!=1||num==0)
            printf("Enter a number other than 0:");
    }
    else
    {
        while(scanf("%f",&num)!=1)
        {
            while((error=getchar())!='\n')
                putchar(error);
            printf(" is not an number.\nPlease enter a number,such as 2.5,-1.78E8 or 3:");
        }
    }
    fflush(stdin);
    return num;
}
