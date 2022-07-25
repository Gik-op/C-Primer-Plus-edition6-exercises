#include <stdio.h>
#include <ctype.h>

#define MAX 256

int Myatoi(const char *arr);

int main()
{
    char string[MAX];
    do
    {
        printf("Hello, please enter a string, and I will turn the string into a number!\n");
        gets(string);
        printf("The number is %d.\n", Myatoi(string));
    }while(Myatoi(string));
    printf("Bye.\n");
    return 0;
}

int Myatoi(const char *arr)
{
    int number=0;
    char label;
    while(*arr)
    {
        if(isdigit(*arr))
        {
            if(*(arr-1)=='-')
                label='-';
            number=10*number+(*arr-'0');
        }
        arr++;
    }
    if(label=='-')
        number*=-1;
    return number;
}
