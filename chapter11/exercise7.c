#include <stdio.h>
#define MAX 256

char* mystrncpy(char*,const char*,int);

int main() {
    char test[MAX],aim[MAX];
    char* ptr;
    printf("Please enter a sentence as the original sentence.\n");
    gets(aim);
    do
    {
        printf("\nPlease enter another sentence, \n"
               "and I'll splice two sentences(enter space to end).\n");
        gets(test);
        if(test[0])
        {
            ptr= mystrncpy(aim,test,20);
            printf("The new sentence is %s.\n",ptr);
            printf("%s\n",aim);//分别验证数组及指针的情况
        }
    }while(test[0]);
    printf("Bye.\n");
    return 0;
}

char* mystrncpy(char *s1,const char *s2,int size)
{
    char *ptr=s1;
    while(*ptr)
        ptr++;
    for(int i=0;i<size;i++)
    {
        *ptr=s2[i];
        if(s2[size-1])
            *ptr='\0';//末尾添加空字符
        ptr++;
    }
    return s1;
}
