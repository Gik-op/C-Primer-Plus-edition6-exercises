#include <stdio.h>

int main()
{
    int count,sum,day;
    sum=count = 0;
    printf("Enter the number of days:");
    scanf("%d",&day);
    while(count++<day)
    {
        sum = sum +count;
    }
    printf("If you get $1 in day1, $2 in day 2......\n"
           "You will get $%d in %d days.\n",sum,day);
    return 0;
}
