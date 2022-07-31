#include <stdio.h>
#include <limits.h>

int ret_open(int num);

int main()
{
    int number,open;
    while(1)
    {
        printf("Hello, please enter a number(q to quit):\n");
        if((scanf("%d",&number))==1)
        {
            open= ret_open(number);
            printf("The number of open bits in %d is %d\n",number,open);
        }
        else
        {
            while(getchar()!='\n')
                continue;
            break;
        }
    }
    printf("Done.");
    return 0;
}

int ret_open(int num)
{
    int count=0;
    int size=CHAR_BIT*sizeof(int);
    for(int i=0;i<size;i++,num>>=1)
    {
        if((num&1)==1)
            count++;
    }
    return count;
}
