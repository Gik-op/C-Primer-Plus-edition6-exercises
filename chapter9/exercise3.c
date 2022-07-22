#include <stdio.h>

void paint(char,int,int);

int main() {
    printf("Hello, World!\n");
    paint('*',5,6);
    return 0;
}

void paint(char ch,int line,int row)
{
    for(int n=0;n<row;n++)
    {
        for(int m=0;m<line;m++)
            printf("%c",ch);
        printf("\n");
    }
}
