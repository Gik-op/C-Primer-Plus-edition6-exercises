#include <stdio.h>
#include <string.h>

int main()
{
    char hello[25];
    int size,count;
    printf("Hello, please enter a word you like:\n");
    scanf("%s",hello);
    size = strlen(hello)-1;
    for(count=size;count>=0;count--)
        printf("%c",hello[count]);
    return 0;
}
