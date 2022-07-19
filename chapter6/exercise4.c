#include <stdio.h>
#define ROW 6

int main()
{
    char alg[30]="ABCDEFGHIJKLMNOPQRSTU";
    int row,line;
    for(row=0;row<ROW;row++)
    {
        int count;
        count = row*(row+1)/2;
        for(line=0;line<=row;line++)
            printf("%c",alg[line+count]);
        printf("\n");
    }
    printf("Hello, World!\n");
    return 0;
}
