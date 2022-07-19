#include <stdio.h>

int main()
{
    char alg[30]="ABCDEFGHIJKLMNOPQRSTU";
    char final;
    int row,ROW,input;
    printf("Please enter an alphabet:");
    scanf("%c",&final);
    ROW=(int)final-64;
    for(row=1;row<=ROW;row++)
    {
        int count;
        count = ROW-row;
        for(int vac=1;vac<=count;vac++)
            printf(" ");
        for(int line=0;line<row;line++)
            printf("%c",alg[line]);
        for(int line2=row-2;line2>=0;line2--)
            printf("%c",alg[line2]);
        printf("\n");
    }
    printf("Hello, World!\n");
    return 0;
}