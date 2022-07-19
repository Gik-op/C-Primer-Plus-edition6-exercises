#include <stdio.h>

int main()
{
    int begin,end;
    int ROW,input;
    printf("Please enter the begin number and the end number:\n");
    input = scanf("%d %d",&begin,&end);
    while(input!=2||(ROW=end-begin)<0)
    {
        fflush(stdin);
        printf("Please enter the begin number and the end number:\n");
        input = scanf("%d %d",&begin,&end);
    }
    printf("number   square   cube\n");
    for(int row=0;row<ROW;row++)
    {
        int num;
        num = begin+row;
        printf("%-8d %-8d %-6d\n",num,num*num,num*num*num);
    }
    printf("Finished!");
    return 0;
}
