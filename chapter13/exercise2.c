#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv [])
{
    int ch;
    FILE *s_file,*t_file;
    if((s_file=fopen(argv[1],"r"))==NULL)
    {
        printf("Can't open %s!\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    t_file=fopen(argv[2],"w");
    while((ch= getc(s_file))!=EOF)
        putc(ch,t_file);
    fclose(s_file);
    fclose(t_file);
    printf("Done!\n");
    return 0;
}
