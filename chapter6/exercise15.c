#include <stdio.h>
#include <string.h>
#define MAX 256

int main()
{
    char art[MAX];
    int count;
    printf("Please enter a sentence.\n");
    scanf("%[^\n]",art);
    count=strlen(art);
    for(int con=count-1;con>=0;con--)
        printf("%c",art[con]);
    printf("\n");
    printf("Finished!\n");
    return 0;
}
