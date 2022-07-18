#include <stdio.h>
#include <string.h>

int main()
{
    char name[40];
    unsigned long long size;
    printf("Please input your name:\n");
   // scanf("%s",name);//不能读入空格后的内容
    scanf("%[^\n]",name);//可读入空格后内容
    printf("\"Hello, %s!\"\n",name);
    printf("\"Hello,%20s\"\n",name);
    printf("\"Hello,%-20s\"\n",name);
    size = strlen(name)+3;
    printf("\"Hello,%*s\"\n",size,name);
    return 0;
}
