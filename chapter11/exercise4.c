#include <stdio.h>
#include <ctype.h>

char* get_word(char*,int);

int main() {
    int size=8;
    char word[size];
    char* ptr;
    printf("Hello, please enter something!\n");
    ptr = get_word(word,size);//word数组存储单词，size确定读取单词的最大长度，返回该数组的地址
    printf("%s",ptr);
    printf("\n");
    printf("%s",word);
    return 0;
}

char* get_word(char* aim,int maxsize)
{
    int i=0;
    while(1)
    {
        if(isspace(aim[i]=getchar()))
            continue;
        else
        {
            while(!isspace(aim[++i]=getchar())&&i<maxsize);
            aim[i]='\0';
            break;
        }
    }
    while(getchar()!='\n')
        continue;//清空缓冲区
    return aim;
}
