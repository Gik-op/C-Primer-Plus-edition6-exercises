#include <stdio.h>
#define MAX 256

int main()
{
    char ch;
    char cha[MAX];
    int count=0,exc1=0,exc2=0;
    printf("Enter some words you want to say( # to terminate).\n");
    while((ch=getchar())!='#')
    {
        if(ch=='.')
        {
            cha[count]='!';
            exc1++;
        }
        else if(ch=='!')
        {
            cha[count]=ch;
            exc2++;
            count++;
            cha[count]='!';
        }
        else
            cha[count]=ch;
        count++;
    }
    for(int n=0;n<count;n++)
        printf("%c",cha[n]);
    printf("Hello, there are %d exchanges,in which "
           "there are %d exchanges(. to !), %d exchanges(! to !!).\n",exc1+exc2,exc1,exc2);
    return 0;
}
