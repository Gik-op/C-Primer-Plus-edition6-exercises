#include <stdio.h>
#define MAX 256

int main()
{
    char ch;
    char cha[MAX];
    int count=0;
    printf("Please enter your word(# to terminate):\n");
    while((ch=getchar())!='#')
    {
        if(ch=='\n')
            continue;
        cha[count]=ch;
        count++;
    }
    for(int n=0;n<count;n++)
    {
        printf("%c%-4d",cha[n],cha[n]);
        if((n+1)%8==0)
            printf("\n");
    }
    printf("\nFinished!\n");
    return 0;
}
