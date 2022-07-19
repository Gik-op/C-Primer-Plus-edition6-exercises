#include <stdio.h>
#define BASIC 100.0
#define RATE 0.08
#define GO 10.0

int main()
{
    double money,add;
    int year=0;
    money=BASIC;
    while(money>0)
    {
        printf("After %d year,you got %f money.\n",year,money);
        add = money*RATE;
        money = money+add-GO;
        year++;

    }
    printf("After %d years, you got no money.\n",year);
    return 0;
}
