#include <stdio.h>
#include <ctype.h>
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

char* get_n(int size,char array[])//自己编的函数，在exercise1的基础上修改
{
    for(int i=0;i<size;i++)
    {
        array[i]=getchar();
        if(isspace(array[i]))
        {
            array[i]='\0';
            break;
        }
    }
    while(getchar()!='\n')//除去输入行内的其他字符
        continue;
    return array;
}

/*char* get_n(int size,char* st)//s_gets()改编的函数
{
    char * array;
    int i=0;
    array=fgets(st,size,stdin);
    if(array)
    {
        while(st[i]!=' '&&st[i]!='\t'&&st[i]!='\n'&&st[i]!='\0')
            i++;
        if(st[i]==' '||st[i]=='\t'||st[i]=='\n')
            st[i]='\0';
        else
            while(getchar()!='\n')//除去输入行内的其他字符
                continue;
    }
    return array;
}*/


