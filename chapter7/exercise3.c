#include <stdio.h>
#define MAX 256

int main()
{
    int num[MAX];
    int count=0,sum1=0,sum2=0;
    int count1=0,count2=0;//对奇数和偶数个数进行计数
    printf("Please enter some numbers(0 to terminate):\n");
    while((scanf("%d",&num[count]))==1&&num[count]!=0)
    {
        if(num[count]%2==0)
        {
            sum2+=num[count];
            count2++;
        }
        else
        {
            sum1+=num[count];
            count1++;
        }
        count++;
    }
    if(count==0)
        printf("Error!");
    else
        printf("There are %d even numbers, average %f.\n"
               "There are %d odd numbers, average %f.\n",count2,
               (float)sum2/(float)count2,count1,(float)sum1/(float)count1);
    return 0;
}
