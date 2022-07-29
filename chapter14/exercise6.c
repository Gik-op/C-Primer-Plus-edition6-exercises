#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40
#define SIZE 8//改成19即可
#define MAX 256

struct player{
    int number;
    char f_name[LEN];
    char l_name[LEN];
    int times;
    int hit;
    int walks;
    int RBI;
    double batting;
};
struct player members[SIZE];

int main()
{
    FILE *fp;
    char file[LEN];
    char line[MAX];
    printf("please enter the name of the file:");
    gets(file);
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("Can't open the file %s!\n",file);
        exit(EXIT_FAILURE);
    }
    while(fgets(line,MAX,fp)!=NULL)
    {
        int rank,num1,num2,num3,num4;
        char name1[LEN],name2[LEN];
        sscanf(line,"%d %s %s %d %d %d %d",&rank,name1,name2,&num1,&num2,&num3,&num4);
        members[rank].number=rank;
        strncpy(members[rank].f_name,name1,LEN);
        strncpy(members[rank].l_name,name2,LEN);
        members[rank].times+=num1;
        members[rank].hit+=num2;
        members[rank].walks+=num3;
        members[rank].RBI+=num4;
    }
    printf("The name of the player:      Times Hits Walks RBI Rate\n");
    for(int count=0;count<SIZE;count++)
    {
        members[count].batting=(double)members[count].hit/(double)members[count].times;
        printf("%-2d %-10s %-14s  %-3d  %-3d  %-3d   %-3d %-4.2f.\n",members[count].number,members[count].f_name,members[count].l_name,
               members[count].times,members[count].hit,members[count].walks,members[count].RBI,members[count].batting);
    }
    fclose(fp);
    printf("Done!\n");
    return 0;
}
