#include <stdio.h>
#include <time.h>

#define SIZE 100

unsigned int* my_rand(unsigned int seed,int num,unsigned int r_num[num]);
void show_num(int num,unsigned int r_num[num]);
void rank_num(int num,unsigned int r_num[num]);

int main()
{
    unsigned int number[SIZE];
    printf("Hello, your random number!\n");
    my_rand((unsigned int)time(0),SIZE,number);
    show_num(SIZE,number);
    rank_num(SIZE,number);
    printf("\nAfter sorting:\n");
    show_num(SIZE,number);
    return 0;
}

unsigned int* my_rand(unsigned int seed,int num,unsigned int r_num[num])
{
    for(int i=0;i<num;i++)
    {
        seed=seed*1103515245+12345;
        r_num[i]=(unsigned int)((seed/65536)%32768)%10+1;
    }
    return r_num;
}

void show_num(int num,unsigned int r_num[num])
{
    for(int c=0;c<num;c++)
    {
        printf("%-2u ",r_num[c]);
        if(c%10==9)
            printf("\n");
    }
}

void rank_num(int num,unsigned int r_num[num])
{
    unsigned int temp;
    for(int top=0;top<num-1;top++)
        for(int seek=top+1;seek<num;seek++)
        {
            if(r_num[top]<r_num[seek])
            {
                temp=r_num[top];
                r_num[top]=r_num[seek];
                r_num[seek]=temp;
            }
        }
}
