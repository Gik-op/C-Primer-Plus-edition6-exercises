#include <stdio.h>

void critic(int *num);

int main()
{
    int units;
    int *ptr=&units;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d",&units);
    while(units!=56)
        critic(ptr);
    printf("You must have looked it up!\n");
    return 0;
}

void critic(int *num)
{
    printf("No luck, my friend.Try again.\n");
    scanf("%d",num);
}
