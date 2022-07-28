#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int main(int argc,char *argv [])
{
    char line[MAX];
    FILE *fp;
    if(argc<3)
    {
        printf("Wrong parameter!\n");
        exit(1);
    }
    if((fp=fopen(argv[2],"r+"))==NULL)
    {
        printf("Can't open the file %s.\n",argv[2]);
        exit(EXIT_FAILURE);
    }
    while((fgets(line,MAX,fp))!=NULL)
    {
        if((strstr(line,argv[1]))!=NULL)
            fputs(line,stdout);
    }
    fclose(fp);
    printf("\nDone!\n");
    return 0;
}
