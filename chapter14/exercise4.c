#include <stdio.h>
#include <string.h>

#define LEN 40
#define SIZE 5

struct name{
    char first[LEN];
    char middle[LEN];
    char last[LEN];
};

struct mode{
    int number;
    struct name person;
};

struct mode info[SIZE]={
        {302039823,"Dribble","Michael","Flossie"},
        {126780954,"Marly","","Salima"},
        {472058732,"Lucy","Sheri","Machali"},
        {669589638,"Maxence","","Alba"},
        {568820093,"Axel","Uni","Anchor"},
};

void print_value(int num,const struct mode aim[num]);
void print_pos(int num,const struct mode (*aim) [num]);

int main() {
    printf("Here is the information:\n");
    print_value(SIZE,info);
    printf("\n");
    print_pos(SIZE,&info);
    printf("\nFinished!\n");
    return 0;
}

void print_value(int num,const struct mode aim[num])
{
    int count;
    for(count=0;count<num;count++)
    {
        if(strcmp(aim[count].person.middle,"\0")!=0)
            printf("%s, %s %c.---- %d\n",aim[count].person.first,
                   aim[count].person.last,aim[count].person.middle[0],aim[count].number);
        else
            printf("%s, %s----%d\n",aim[count].person.first,
                   aim[count].person.last,aim[count].number);
    }
}

void print_pos(int num,const struct mode (*aim) [num])
{
    int count;
    for(count=0;count<num;count++)
    {
        if(strcmp((*aim)[count].person.middle,"\0")!=0)
            printf("%s, %s %c.---- %d\n",(*aim)[count].person.first,
                   (*aim)[count].person.last,(*aim)[count].person.middle[0],(*aim)[count].number);
        else
            printf("%s, %s----%d\n",(*aim)[count].person.first,
                   (*aim)[count].person.last,(*aim)[count].number);
    }
}
