#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 40
#define SIZE 3

typedef struct {
    char first[NUM];
    char last[NUM];
}Name;

int my_comp(const void *p1,const void *p2);
void fill_str(int size,Name person[size]);
void show_str(int size,const Name person[size]);

int main()
{
    Name students[SIZE];
    fill_str(SIZE,students);
    puts("Random list:");
    show_str(SIZE,students);
    qsort(students,SIZE,sizeof(Name),my_comp);
    puts("\nSorted list:");
    show_str(SIZE,students);
    return 0;
}

int my_comp(const void *p1,const void *p2)
{
    const Name *a1=(const Name *)p1;
    const Name *a2=(const Name *)p2;
    int res=strcmp(a1->first,a2->first);
    if(res==0)
       res=strcmp(a1->first,a2->first);
    return res;
}

void fill_str(int size,Name person[size])
{
    printf("Get %d names:\n",size);
    for(int i=0;i<size;i++)
    {
        char name[2][NUM];
        printf("No.%d  The first name:",i+1);
        gets(name[0]);
        strncpy(person[i].first,name[0],NUM-1);
        printf("No.%d  The last name:",i+1);
        gets(name[1]);
        strncpy(person[i].last,name[1],NUM-1);
    }
}

void show_str(int size,const Name person[size])
{
    for(int i=0;i<size;i++)
    {
        printf("* %-10s %-14s ",person[i].first,person[i].last);
        if(i%3==2)
            printf("\n");
    }
    if(size%3!=0)
        printf("\n");
}
