#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 256

int base_2(int n);
int binary_in(char *st);
char * itobs(int num,char *ps);

int main(int argc,char *argv[])
{
    int integer[2];
    char binary[2][MAX];
    char result[2][MAX];
    if(argc==3)
    {
        for(int index=0;index<2;index++)
        {
            strncpy(binary[index],argv[index+1],MAX-1);
            integer[index]= binary_in(binary[index]);
        }
        printf("~%s = %s  ~%s = %s\n",binary[0],itobs(~integer[0],result[0]),
               binary[1],itobs(~integer[1],result[1]));
        printf("%s & %s = %s\n",binary[0],binary[1],itobs(integer[0]&integer[1],result[0]));
        printf("%s | %s = %s\n",binary[0],binary[1],itobs(integer[0]|integer[1],result[0]));
        printf("%s ^ %s = %s\n",binary[0],binary[1],itobs(integer[0]^integer[1],result[0]));
    }
    else
        printf("Invalid parameter!");
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

char * itobs(int num,char *ps)
{
    int i;
    const static int size =CHAR_BIT*sizeof(char);//此处采取八位，可根据需要调整大小
    for(i=size-1;i>=0;i--,num>>=1)
        ps[i]=(01&num)+'0';
    ps[size]='\0';
    return ps;
}
