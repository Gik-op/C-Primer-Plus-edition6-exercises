#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 256

int call_n(void);

int main()
{
    char input[MAX];
    char *endptr;
    long int number;
    do
    {
        printf("Hello, please enter a number!(q to quit)\n");
        gets(input);
        number=strtol(input,&endptr,10);
        for(int i=0;i<number;i++)
            call_n();
    }while(isdigit(input[0]));
    printf("Done.\n");
    return 0;
}

int call_n(void)
{
    static int count=0;
    count++;
    printf("You called \"call_n\" %d %s.\n",count,count==1?"time":"times");
    return count;
}

