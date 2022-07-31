#include <stdio.h>
#include <limits.h>

#define size CHAR_BIT* sizeof(unsigned int)//总位数

unsigned int rotate_l(unsigned int aim,int pos);
unsigned int base_2(int n);
char * itobs(unsigned int num,char *ps);

int main()
{
    int bits;
    unsigned int number;
    char binary[2][size+1];
    while(1)
    {
        printf("Hello, please enter a number and the bits you want to move(q to quit):\n");
        if((scanf("%u %d",&number,&bits))==2)
        {
            printf("%ud %s.\n",number, itobs(number,binary[0]));
            number=rotate_l(number,bits);
            printf("After moving:%ud %s.\n",number, itobs(number,binary[1]));
        }
        else
            break;
    }
    printf("Done.");
    return 0;
}

unsigned int rotate_l(unsigned int aim,int pos)
{
    unsigned int mask= base_2(size-1);
    unsigned int replace=0;
    for(int move=0;move<pos;move++)
    {
        if((aim&mask)==mask)
            replace=1;//最左端的位为1，要变，为0则无需改变
        aim<<=1;
        if(replace==1)
            aim|=replace;//若为1，打开最右端的位
    }
    return aim;
}

unsigned int base_2(int n)
{
    unsigned int power=1;
    for(int i=0;i<n;i++)
        power*=2;
    return power;
}

char * itobs(unsigned int num,char *ps)
{
    int i;
    for(i=size-1;i>=0;i--,num>>=1)
        ps[i]=(int)(1&num)+'0';
    ps[size]='\0';
    return ps;
}
