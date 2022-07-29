#include <stdio.h>
#include <string.h>

#define LEN 20
#define CSIZE 4

struct name{
    char first[LEN];
    char last[LEN];
};

struct student{
    struct name Name;
    double grade[3];
    double average;
};

char * s_gets(char *st,int n);

int main() {
    int count=0;
    double all_aver=0;
    char input[LEN];
    struct student students[CSIZE]={
            {"Elon","Mask"},
            {"Maxence","Elle"},
            {"Victoria","Sun"},
            {"Lestat","Lioncourt"},
    };
    printf("Please enter the name of the student:");
    while(count<CSIZE)
    {
        int theOne=-1;
        s_gets(input,LEN);
        sscanf(input,"%s",input);
        for(int i=0;i<CSIZE;i++)
        {
            if(strcmp(input,students[i].Name.first)==0)
            {
                theOne=i;
                break;
            }
        }
        if(theOne>=0)
        {
            printf("Please enter the student's three scores(eg 89 98 92):");
            gets(input);
            while(sscanf(input,"%lf %lf %lf",&students[theOne].grade[0],
                         &students[theOne].grade[1],&students[theOne].grade[2])!=3)
            {
                printf("Wrong input!Input again：");
                gets(input);
            }
            students[theOne].average=(students[theOne].grade[0]+students[theOne].grade[1]+students[theOne].grade[2])/3.0;
            count++;
            if(count<CSIZE)
                printf("Please enter the next student's name:");
        }
        else
            printf("Can't find the student!Input again:");
    }
    printf("Here are the grades:\n");
    for(int n=0;n<CSIZE;n++)
    {
        printf("%s %s\nGrades:%.2f %.2f %.2f\nAverage:%.2f\n",students[n].Name.first,students[n].Name.last,
               students[n].grade[0],students[n].grade[1],students[n].grade[2],students[n].average);
        all_aver+=students[n].average;
    }
    all_aver/=CSIZE;
    printf("The average of all the students is %.2f.\n",all_aver);
    printf("Done!\n");
    return 0;
}

char * s_gets(char *st,int n)
{
    char *ret_val;
    char *find;
    ret_val=fgets(st,n,stdin);
    if(ret_val)
    {
        find=strchr(st,'\n');
        if(find)
            *find='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}
