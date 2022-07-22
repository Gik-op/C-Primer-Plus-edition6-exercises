#include <stdio.h>
#include <ctype.h>
#define MAX 256

int ischar(char);

int main()
{
    char ch;
    int count=0;
    int number[MAX];
    printf("Please enter some sentences.\n");
    while((ch=getchar())!=EOF)
    {
        number[count]=ischar(ch);
        count++;
    }
    for(int n=0;n<count;n++)
    {
        if(number[n]!=-1)
            printf("This is a letter, rank %d\n",number[n]);
        else
            printf("This isn't a letter.\n");
    }
    printf("Bye.");
    getchar();
    return 0;
}

int ischar(char ch)
{
    if(isalpha(ch))
        return tolower(ch)-96;
    else
        return -1;
}
