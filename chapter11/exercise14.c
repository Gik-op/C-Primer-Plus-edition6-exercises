#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv [])
{
    int flag;
    int pow=strtol(argv[2],NULL,10);
    double result=1;
    double base = strtod(argv[1],NULL);
    if(pow<0)
    {
        pow*=-1;
        flag=1;
    }
    else
        flag=0;
    for(int n=0;n<pow;n++)
        result*=base;//确保任何数零次幂为1
    if(base==0)
    {
        result=1;//确保零的任何次幂为1
        if(pow==0)
            printf("Zero to the 0th power is undefined.\n");//对0的0次幂的处理
    }
    if(flag==1)
        result=1.0/result;
    printf("Hello, %.2f^%-d = %f.\n",base,strtol(argv[2],NULL,10),result);
    return 0;
}
