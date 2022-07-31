#include <stdio.h>
#include <stdbool.h>

int base_2(int n);
bool find_pos(int num,int pos);

int main()
{
    int number,pos;
    bool isfind;
    while(1)
    {
        printf("Hello, please enter a number and the position you want to check(q to quit):\n");
        if((scanf("%d %d",&number,&pos))==2)
        {
            isfind= find_pos(number,pos);
            printf("The value at bit %d is %d.\n",pos,isfind?1:0);
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

bool find_pos(int num,int pos)
{
    bool result=false;
    int tool= base_2(pos-1);
    if((num&tool)==tool)
        result=true;
    return result;
}

int base_2(int n)
{
    int pow=1;
    for(int i=0;i<n;i++)
        pow*=2;
    return pow;
}
