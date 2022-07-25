#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 256

int main(int argc,char *argv [])
{
    char ch;
    char capacity[MAX];
    int count=0,size=0;
    printf("Please input something.(EOF to end)\n");
    while((ch=getchar())!=EOF)
    {
        capacity[size]=ch;
        size++;
        if(size+1==MAX)
        {
            while(getchar()!=EOF)
                continue;
            printf("The file exceeds the maximum capacity!\n");//处理输入超过数组最大容量的情况
            break;
        }
    }
    while(capacity[count]!=EOF&&count<size)
    {
        if(!strcmp(argv[1],"-u"))
            putchar(toupper(capacity[count]));
        else if(!strcmp(argv[1],"-l"))
            putchar(tolower(capacity[count]));
        else
            putchar(capacity[count]);
        count++;
    }
    return 0;
}
