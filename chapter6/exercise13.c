#include <stdio.h>

int power2(int);

int main()
{
    int num[8];
    for(int count=0;count<8;count++)
        num[count]=power2(count);
    int sig=0;
    do
    {
        printf("%-5d",num[sig]);
        sig++;
    }while(sig<8);
    return 0;
}

int power2(int m)
{
    int sum=1;
    for(int q=0;q<m;q++)
        sum*=2;
    return sum;
}
