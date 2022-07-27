#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
void append(FILE *source,FILE *dest);

int main(int argc,char *argv [])
{
    FILE *fa,*fs;
    int files=2;
    int ch;
    printf("On the cmd,the first file is the file to be added,followed by the file to be added.\n");
    if((fa=fopen(argv[1],"a+"))==NULL)
    {
        fprintf(stderr,"Can't open %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)
    {
        fputs("Can't create output buffer\n",stderr);
        exit(EXIT_FAILURE);
    }
    while(files<argc)
    {
        if(strcmp(argv[files],argv[1])==0)
            fputs("Can't append file to itself\n",stderr);
        else if((fs=fopen(argv[files],"r"))==NULL)
            fprintf(stderr,"Can't open %s\n",argv[files]);
        else
        {
            if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)
            {
                fputs("Can't create input buffer\n",stderr);
                continue;
            }
            append(fs,fa);
            if(ferror(fs)!=0)
                fprintf(stderr,"Error in reading file %s.\n",argv[files]);
            if(ferror(fa)!=0)
                fprintf(stderr,"Error in writing file %s.\n",argv[1]);
            fclose(fs);
            printf("File %s appended.\n",argv[files]);
            files++;
        }
    }
    printf("Done appending. %d files appended.\n",argc-2);
    rewind(fa);
    printf("%s contents:\n",argv[1]);
    while((ch=getc(fa))!=EOF)
        putchar(ch);
    fclose(fa);
    puts("\nDone displaying.");
    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];
    while((bytes=fread(temp,sizeof(char),BUFSIZE,source))>0)
        fwrite(temp,sizeof(char),bytes,dest);
}
