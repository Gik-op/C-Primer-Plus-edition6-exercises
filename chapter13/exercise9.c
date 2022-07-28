#include <stdio.h>
#include <stdlib.h>

#define MAX 41

int main()
{
    FILE *fp;
    char words[MAX];
    char line[MAX];
    int rank=1;
    if((fp=fopen("wordy","a+"))==NULL)
    {
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    rewind(fp);
    while (fgets(line, MAX, fp) != NULL)
        rank++;
    puts("Enter words to add to the file;press the # key"
         " at the beginning of a line to terminate.");
    while((fscanf(stdin,"%40s",words)==1)&&(words[0]!='#'))
    {
        fprintf(fp,"%d %s\n",rank,words);
        rank++;
    }
    puts("File contents:");
    rewind(fp);
    while(fgets(line,MAX,fp)!=NULL)
        fputs(line,stdout);
    puts("Done!");
    if(fclose(fp)!=0)
        fprintf(stderr,"Error closing file\n");

    return 0;
}
