#include <stdio.h>
#include <ctype.h>

char get_first(void);

int main()
{
    char cha;
    printf("Hello, please enter something!\n");
    cha=get_first();
    printf("%c",cha);
    return 0;
}

char get_first(void)
{
    char ch;
    while(isspace((ch=getchar())));
    return ch;
}
