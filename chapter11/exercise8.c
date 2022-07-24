#include <stdio.h>
#define MAX 256

char* string_in(char *s1,char *s2);//检查s2是否包含于s1当中

int main() {
    char test[MAX],aim[MAX];
    char *ptr;
    printf("Please enter a string.\n");
    gets(aim);
    do
    {
        printf("\nPlease enter a sentence, \n"
               "and I'll check whether this sentence contains the previous string.\n"
               "(enter space to end).\n");
        gets(test);
        if(test[0])
        {
            ptr = string_in(test,aim);
            if(ptr!=NULL)
                printf("Yes, I find %s in %s.\n",aim,ptr);
            else
                printf("No,I can't find it.\n");
        }
    }while(test[0]);
    printf("Bye.\n");
    return 0;
}

char* string_in(char *s1,char *s2)
{
    char *ptr1=s1;
    char *ptr2;
    char *result=NULL;
    while(*ptr1)
    {
        ptr2=s2;
        if(*ptr1==*ptr2)//对s1遍历，找到s2首字符后开始比较
        {
            result=ptr1;
            while(*ptr2)
            {
                if(*ptr1!=*ptr2)
                {
                    result=NULL;
                    break;
                }
                ptr1++;
                ptr2++;
            }//依次对比，完全相同时返回指针
            if(result!=NULL)//PS 对空字符不能直接解引用作为判断条件
                break;//找到后即可跳出循环
        }
        ptr1++;
    }
    return result;
}
