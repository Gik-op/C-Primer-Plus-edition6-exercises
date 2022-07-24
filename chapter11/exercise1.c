#include <stdio.h>
#define MAX 256

char* get_n(int,char*);

int main()
{
    int n=20;
    char aim[MAX];
    char* ptr;
    printf("Hello,please enter %d characters!\n",n);
    ptr = get_n(n,aim);
    printf("%s",ptr);
    return 0;
}

char* get_n(int size,char array[])
{
    for(int i=0;i<size;i++)
        array[i]=getchar();
    while(getchar()!='\n')//除去输入行内的其他字符
        continue;
    return array;
}
