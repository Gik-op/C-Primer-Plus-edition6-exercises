#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 100

void select_rand(int size,const int arr[size],int num);
int * assign(int size,int arr[size]);

int main()
{
    int test[SIZE];
    int selection;
    assign(SIZE,test);
    printf("Hello, please enter the number of selections(1--%d):",SIZE);
    while(scanf("%d",&selection)==1&&selection>=1&&selection<=SIZE)
    {
        select_rand(SIZE,test,selection);
        printf("The number of selections(1--%d,q to quit):",SIZE);
    }
    printf("Bye.");
    return 0;
}

int * assign(int size,int arr[size])
{
    int *ptr=arr;
    for(int i=0;i<size;i++)
        *(ptr+i)=i+1;
    return ptr;
}

void select_rand(int size,const int arr[size],int num)
{
    int select[num];
    int seek_num[num];
    srand((unsigned int)time(0));
    for(int i=0;i<num;i++)
    {
        int random;
        bool repeat;
        do{
            repeat=false;
            random=(rand())%size;
            for(int k=0;k<i;k++)
                if(random==seek_num[k])
                {
                    repeat=true;
                    break;
                }
        }while(repeat);
        select[i]=arr[random];
        seek_num[i]=random;
    }
    for(int i=0;i<num;i++)
    {
        printf("%2d: %-4d ",i+1,select[i]);
        if(i%10==9)
            printf("\n");
    }
    if(num%10!=0)
        printf("\n");
}
