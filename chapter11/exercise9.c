#include <stdio.h>
#include <string.h>
#define MAX 256

char* invert(char *ptr);

int main()
{
    char test[MAX];
    char *ptr;
    do
    {
        printf("\nPlease enter a string(enter space to end).\n");
        gets(test);
        if(test[0])
        {
            printf("Your string:%s.\n",test);
            ptr = invert(test);
            printf("After inverting:%s.\n",ptr);
        }
    }while(test[0]);
    printf("Bye.\n");
    return 0;
}

char* invert(char *ptr)
{
    unsigned long long size=strlen(ptr);
    char temp;
    char *aim=ptr;
    for(int i=0;i<size/2;i++)
    {
        temp=ptr[i];
        ptr[i]=ptr[size-i-1];
        ptr[size-i-1]=temp;
    }
    return aim;
}
