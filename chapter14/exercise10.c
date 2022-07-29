#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 256

void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);

int main()
{
    char content[MAX];
    char choice[MAX];
    void (*pfun[3])(char *)={ToUpper, ToLower, Transpose};
    printf("Please enter a string:\n");
    gets(content);
    printf("Please choose a function,enter its letter label:\n");
    printf("a)ToUpper  b)ToLower  c)Transpose\n");
    gets(choice);
    while(strchr("abc",choice[0])==NULL)
    {
        printf("Invalid input.Input again:");
        gets(choice);
    }
    switch(choice[0])
    {
        case 'a':pfun[0](content);break;
        case 'b':pfun[1](content);break;
        case 'c':pfun[2](content);break;
    }
    puts(content);
    printf("Done!\n");
    return 0;
}

void ToUpper(char *arr)
{
    while(*arr)
    {
        *arr=toupper(*arr);
        arr++;
    }
}

void ToLower(char *arr)
{
    while(*arr)
    {
        *arr=tolower(*arr);
        arr++;
    }
}

void Transpose(char *arr)
{
    while(*arr)
    {
        if(islower(*arr))
            *arr=toupper(*arr);
        else if(isupper(*arr))
            *arr= tolower(*arr);
        arr++;
    }
}
