#include <stdio.h>

#define SIZE 100
#define GROUP 10

unsigned int* my_rand(unsigned int seed,int num,unsigned int r_num[num]);
void test_rand(int num,const unsigned int r_num[num],int base);

int main()
{
    unsigned int get[GROUP][SIZE];
    printf("Hello, World!\n");
    for(int count=0;count<GROUP;count++)
        my_rand(count,SIZE,get[count]);
    for(int count=0;count<GROUP;count++)
    {
        printf("In group %d:\n",count+1);
        test_rand(SIZE,get[count],10);
    }
    printf("Done!");
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

void test_rand(int num,const unsigned int r_num[num],int base_max)//最后一个值为范围的最大值
{
    int times[base_max];
    for(int c=0;c<base_max;c++)
        times[c]=0;//初始化数组中的每个值
    for(int i=0;i<num;i++)
    {
        for(int k=0;k<base_max;k++)
        {
            if(r_num[i]==(k+1))
            {
                times[k]++;
                break;
            }
        }
    }
    for(int c=0;c<base_max;c++)
    {
        printf("number %d: %d ",c+1,times[c]);//报告各数字出现次数
        if(c%5==4)
            printf("\n");
    }

}
