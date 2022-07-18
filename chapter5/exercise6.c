#include <stdio.h>

int main()
{
    int count,sum,day;
    sum=count = 0;
    printf("Enter the number of days:");
    scanf("%d",&day);
    while(count++<day)
    {
        sum = sum +count*count;
        printf("You get $%3d in day%02d.\n",count*count,count);
    }
    printf("You will get $%d in %d days.\n",sum,day);
    return 0;
}
