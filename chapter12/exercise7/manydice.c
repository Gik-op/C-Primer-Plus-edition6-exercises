//manydice.c 多次掷骰子模拟程序
//与 diceroll.c一起编译
#include <stdio.h>
#include <stdlib.h>
#include "diceroll.h"

#define MAX 256

int main(void)
{
    int sides,dice,sets;
    char choice[MAX],dice_set[MAX];
    char *Endptr;
    printf("Enter the number of sets;enter q to stop:");
    gets(choice);
    while(choice[0]!='q')
    {
        sets=strtol(choice,&Endptr,10);
        if(sets!=0)
        {
            int result[sets];
            printf("How many sides and how many dice?");
            gets(dice_set);
            while((sscanf(dice_set,"%d %d",&sides,&dice))!=2||sides<2||dice<1)
            {
                printf("Wrong input!\nHow many sides and how many dice?");
                gets(dice_set);
            }
            printf("Here are %d %s of %d %d-sided throws.\n",sets,sets==1?"set":"sets",dice,sides);
            for(int count=0;count<sets;count++)
            {
                result[count]=roll_n_dice(dice,sides);
                printf("%d ",result[count]);
                if(count%10==9)
                    printf("\n");
            }
        }
        else
            printf("Wrong input! Input again!");
        printf("\nHow many sets? Enter q to stop:");
        gets(choice);
    }
    printf("Done.");
    return 0;
}