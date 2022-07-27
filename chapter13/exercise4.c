#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv [])
{
    int count=1;
    if(argc==1)
    {
        printf("There is no actionable file name.\n");
        exit(EXIT_FAILURE);
    }
    while(count<argc)
    {
        int ch;
        FILE *fp;
        if((fp=fopen(argv[count],"r"))==NULL)
        {
            printf("Can't open %s.\n",argv[count]);
            continue;
        }
        printf("\nFile %s contents:\n",argv[count]);
        while((ch=getc(fp))!=EOF)
            putc(ch,stdout);
        fclose(fp);
        count++;
    }
    printf("\nDone!\n");
    return 0;
}
