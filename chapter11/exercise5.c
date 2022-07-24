#include <stdio.h>
#define MAX 256

char* findch(char*,char);

int main()
{
    char test[MAX],aim[MAX];
    char* ptr;
    printf("Please enter a character.\n");
    gets(aim);
    do
    {
        printf("\nPlease enter a sentence, \n"
               "and I'll check whether there is %c in it.\n",aim[0]);
        gets(test);
        ptr= findch(test,aim[0]);
        if(*ptr)
            printf("Hey,you get %c in %s!\n",aim[0],ptr);
        else
            printf("Oh no, I can't find it.\n");
    }while(*ptr);
    printf("Bye.\n");
    return 0;
}

char* findch(char* arr,char aim)
{
    char* ptr;
    ptr=arr;
    while(*ptr!=aim)
    {
        ptr++;
        if(*ptr=='\0')
            break;
    }
    return ptr;
}
