#include <stdio.h>
#include <stdbool.h>
#define RATE1 0.15
#define RATE2 0.20
#define RATE3 0.25
#define BASE1 45
#define BASE2 75
#define add_time 1.5

void picture(void);
bool letter(char);

int main()
{
    char choice;
    int input;
    double salary,tax,per=0,time;
    picture();
    printf("Enter the number corresponding to the desired pay rate or action.\n");
    printf("a) $8.75hr     b) $9.33hr\nc) $10.00hr    d) $11.20hr\nq) quit\n");
    picture();
    input=scanf("%c",&choice);
    while(input!=1||!letter(choice))
    {
        fflush(stdin);
        picture();
        printf("Enter the number corresponding to the desired pay rate or action.\n");
        printf("a) $8.75hr     b) $9.33hr\nc) $10.00hr    d) $11.20hr\nq) quit\n");
        picture();
        input = scanf("%c", &choice);
    }
    if(choice!='q')
    {
        switch(choice)
        {
            case 'a':per=8.75;break;
            case 'b':per=9.33;break;
            case 'c':per=10.00;break;
            case 'd':per=11.20;break;
            default:break;
        }
        printf("Please enter your working time:");
        scanf("%lf",&time);
        if(time>40.0)
            time=add_time*time;
        salary=per*time;
        if(salary<=300.0)
            tax=salary*RATE1;
        else if(salary<450.0)
            tax=BASE1+(salary-300)*RATE2;
        else
            tax=BASE2+(salary-450)*RATE3;
        printf("You got %.2f money and %.2f tax, so actually you got %.2f.",salary,tax,salary-tax);
    }
    printf("Finished!");
    return 0;
}

void picture(void)
{
    for(int n=0;n<100;n++)
        printf("*");
    printf("\n");
}

bool letter(char n)
{
    if(n=='a'||n=='b'||n=='c'||n=='d'|n=='q')
        return true;
    else
        return false;
}
