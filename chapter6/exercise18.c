#include <stdio.h>
#define DENBA 150

int main()
{
    int week,friend;
    week=0;
    friend=5;
    while(friend<DENBA)
    {
        printf("In week %d, Rabnud had %d friends.\n",week,friend);
        week++;
        friend=(friend-week)*2;
    }
    printf("Well,in week %d, Rabnud got %d friends, more than Denba number(%d)!\n",week,friend,DENBA);
    return 0;
}
