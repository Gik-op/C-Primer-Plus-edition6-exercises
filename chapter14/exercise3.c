#include <stdio.h>
#include <string.h>
char * s_gets(char *st,int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void rank_in_titl(int num,struct book *lib[num]);
void rank_in_value(int num,struct book *lib[num]);
void show_rank(int num,struct book *lib[num]);

int main() {
    struct book library[MAXBKS];
    struct book * rank[MAXBKS];
    int count=0;
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while(count<MAXBKS&&s_gets(library[count].title,MAXTITL)!=NULL&&library[count].title[0]!='\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author,MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f",&library[count].value);
        rank[count]=&library[count];//store a pointer which is pointing to the struct library[count]
        count++;
        while(getchar()!='\n')
            continue;
        if(count<MAXBKS)
            printf("Enter the next title.\n");
    }
    if(count>0)
    {
        printf("Here is the list of your books:\n");
        show_rank(count,rank);
        rank_in_titl(count,rank);
        printf("\nAlphabetical order by title:\n");
        show_rank(count,rank);
        printf("\nSort by price:\n");
        rank_in_value(count,rank);
        show_rank(count,rank);
        /*for(index=0;index<count;index++)
            printf("%s by %s: $%.2f\n",library[index].title,library[index].author,library[index].value);*/
    }
    else
        printf("No books? Too bad.\n");
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

void rank_in_titl(int num,struct book *lib[num])
{
    struct book *ptr;
    for(int n=0;n<num-1;n++)
        for(int m=n+1;m<num;m++)
        {
            if(strcmp(lib[n]->title,lib[m]->title)>0)
            {
                ptr=lib[n];
                lib[n]=lib[m];
                lib[m]=ptr;
            }
        }
}

void rank_in_value(int num,struct book *lib[num])
{
    struct book *ptr;
    for(int n=0;n<num-1;n++)
        for(int m=n+1;m<num;m++)
        {
            if(lib[n]->value>lib[m]->value)
            {
                ptr=lib[n];
                lib[n]=lib[m];
                lib[m]=ptr;
            }
        }
}

void show_rank(int num,struct book *lib[num])
{
    for(int index=0;index<num;index++)
        printf("%s by %s: $%.2f\n",lib[index]->title,lib[index]->author,lib[index]->value);
}
