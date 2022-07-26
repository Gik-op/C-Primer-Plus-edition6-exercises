//掷骰子模拟程序
#include <stdlib.h>
#include "diceroll.h"

static int rollem(int sides)//每一次投掷的值
{
    int roll;
    roll=rand()%sides+1;
    return roll;
}

int roll_n_dice(int dice,int sides)
{
    int total=0;
    for(int d=0;d<dice;d++)
        total+= rollem(sides);
    return total;
}
