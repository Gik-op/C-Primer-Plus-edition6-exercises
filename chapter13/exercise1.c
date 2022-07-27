#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 15

int main()
{
    int ch;
    char file[SIZE];
    char *find;
    FILE *fp;
    unsigned long count=0;
    printf("Please enter the name of the file:");
    fgets(file,SIZE,stdin);
    find=strchr(file,'\n');
    if(find)
        *find='\0';//读入的内容包括了那个该死的换行符
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("Can't open %s\n",file);
        exit(EXIT_FAILURE);
    }
    while((ch=getc(fp))!=EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    printf("\nFile %s has %lu characters.\n",file,count);
    return 0;
}
