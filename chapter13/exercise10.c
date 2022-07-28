#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main()
{
    char name[MAX];
    char choice[MAX];
    char content[MAX];
    long pos;
    FILE *file;
    printf("Hello, please enter the name of your file:\n");
    gets(name);
    if((file=fopen(name,"r"))==NULL)
    {
        printf("Can't open the file %s.\n",name);
        exit(EXIT_FAILURE);
    }
    printf("Please enter a number to determine a location to start reading:");
    gets(choice);
    pos=strtol(choice,NULL,10);
    while(pos>=0)
    {
        fseek(file,pos,SEEK_SET);
        if((fgets(content,MAX,file))!=NULL)
            fputs(content,stdout);
        else
            printf("Wrong!Out of file words!\n");
        printf("A number to determine the location(negative or non-numeric to stop):");
        gets(choice);
        pos=strtol(choice,NULL,10);
    }
    printf("Done.");
    return 0;
}
