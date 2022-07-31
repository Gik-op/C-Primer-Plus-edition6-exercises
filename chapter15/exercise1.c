#include <stdio.h>
#include <string.h>

#define MAX 256

int binary_in(char *st);
int base_2(int n);

int main()
{
    int number;
    char input[MAX];
    while(1)
    {
        printf("Hello, please enter a binary string:");
        gets(input);
        if(input[0]=='1'||input[0]=='0')//鲁棒性不够，想办法检测字符串
        {
            number=binary_in(input);
            printf("%s in binary is %d in decimalism.\n",input,number);
        }
        else
            break;
    }
    printf("Done!");
    return 0;
}

int binary_in(char *st)
{
    int integer=0;
    int length=strlen(st);
    for(int i=0;i<length;i++)
        integer+=(st[i]-'0')*base_2(length-i-1);
    return integer;
}

int base_2(int n)
{
    int pow=1;
    for(int i=0;i<n;i++)
        pow*=2;
    return pow;
}
