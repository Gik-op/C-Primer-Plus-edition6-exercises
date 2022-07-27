#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 256

int main()
{
    int ch;
    char source[SIZE],target[SIZE];
    FILE *s_file,*t_file;
    printf("Please enter the name of the primary file:");
    gets(source);
    if((s_file=fopen(source,"r"))==NULL)
    {
        printf("Can't open %s!\n",source);
        exit(EXIT_FAILURE);
    }
    printf("Please enter the name of the new file:");
    gets(target);
    t_file=fopen(target,"w");
    while((ch= getc(s_file))!=EOF)
        putc(toupper(ch),t_file);
    fclose(s_file);
    fclose(t_file);
    printf("Done!\n");
    return 0;
}
