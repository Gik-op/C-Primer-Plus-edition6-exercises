#include <stdio.h>
#include <ctype.h>
#define MAX 256

char* delete_s(char *arr);

int main() {
    char test[MAX];
    char *ptr;
    do
    {
        printf("\nHello, please enter a sentence and "
               "I'll delete the space in it!\n(enter space to end)\n");
        gets(test);
        if(test[0])
        {
            printf("The original sentence: %s\n",test);
            ptr = delete_s(test);
            printf("After deleting: %s\n",ptr);
        }
    }while(test[0]);
    printf("Bye.");
    return 0;
}

char* delete_s(char *arr)
{
    char *ptr=arr;
    char *answer=arr;//固定为arr字符串开始的位置
    while(*ptr)
    {
        if(!isspace(*ptr))
        {
            *arr=*ptr;
            arr++;
        }
        ptr++;
    }
    return answer;//不知道为什么结尾几个字符会重复出现一次
}
