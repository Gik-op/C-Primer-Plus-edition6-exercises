#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main()
{
    FILE *in,*out;
    int ch;
    int count=0;
    char name[LEN],o_name[LEN];
    printf("Hello, please enter the name of the file you want to compress:\n");
    gets(name);
    if((in=fopen(name,"r"))==NULL)
    {
        fprintf(stderr,"I couldn't open the file %s.\n",name);
        exit(EXIT_FAILURE);
    }
    strncpy(o_name,name,strlen(name)-5);
    strcat(o_name,"red.txt");
    if((out=fopen(o_name,"w"))==NULL)
    {
        fprintf(stderr,"Can't create output file.\n");
        exit(EXIT_FAILURE);
    }
    while((ch=getc(in))!=EOF)
        if(count++%3==0)
            putc(ch,out);
    if(fclose(in)!=0||fclose(out)!=0)
        fprintf(stderr,"Error in closing files!\n");
    printf("Done!\n");
    return 0;
}
