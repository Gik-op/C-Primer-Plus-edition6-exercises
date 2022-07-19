#include <stdio.h>
#define SIZE 8

void circle(int*);

int main()
{
    int num[SIZE],sum[SIZE];
    printf("Please enter 8 numbers to begin your happy journey.\n");
    for(int count=0;count<SIZE;count++)
    {
        scanf("%d",&num[count]);
    }
    sum[0]=num[0];
    for(int count2=1;count2<SIZE;count2++)
    {
        sum[count2]=num[count2]+sum[count2-1];
    }
    circle(num);
    circle(sum);
    printf("Well done!\n");
    return 0;
}

void circle(int ch[SIZE])
{
    for(int m=0;m<SIZE;m++)
        printf("%-3d",ch[m]);
    printf("\n");
}
