#include <stdio.h>

int main()
{
    int begin,end;
    int input;
    printf("Please enter the begin number and the end number:\n");
    input = scanf("%d %d",&begin,&end);
    while(input!=2)
    {
        fflush(stdin);
        printf("Please enter the begin number and the end number:\n");
        input = scanf("%d %d",&begin,&end);
    }
   while(end-begin>0)
   {
       int sum=0;
       for(int num=begin;num<=end;num++)
       {
           sum+=num*num;
       }
       printf("The sums of squares from %d to %d is %d.\n",begin*begin,end*end,sum);
       printf("Please enter the begin number and the end number:\n");
       input = scanf("%d %d",&begin,&end);
       while(input!=2)
       {
           fflush(stdin);
           printf("Please enter the begin number and the end number:\n");
           input = scanf("%d %d",&begin,&end);
       }
   }
    printf("Finished!");
    return 0;
}