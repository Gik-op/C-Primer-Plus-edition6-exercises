#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 14
#define SIZE 12
#define MAX 256

struct plane{
    int number;
    int book;
    char f_name[LEN];
    char l_name[LEN];
};

void menu(void);
char get_a(void);
char * s_gets(char *st,int n);
int choose_a(int num,struct plane arr[num]);
void choose_b(int num,struct plane arr[num]);
void choose_c(int num,struct plane arr[num]);
void choose_d(int num,struct plane (*arr)[num]);
void choose_e(int num,struct plane (*arr)[num]);


int main()
{
    char answer;
    struct plane flight[SIZE]={
            {1,0},
            {2,0},
            {3,0},
            {4,0},
            {5,0},
            {6,0},
            {7,0},
            {8,0},
            {9,0},
            {10,0},
            {11,0},
            {12,0},
    };
    menu();
    answer=get_a();
    while(answer!='f')
    {
        switch(answer)
        {
            case'a':
                choose_a(SIZE,flight);
                break;
            case'b':
                choose_b(SIZE,flight);
                break;
            case'c':
                choose_c(SIZE,flight);
                break;
            case'd':
                choose_d(SIZE,&flight);
                break;
            case'e':
                choose_e(SIZE,&flight);
                break;
            default:
                break;
        }
        menu();
        answer=get_a();
    }
    printf("Finished!\n");
    return 0;
}

void menu(void)
{
    printf("\nTo choose a function, enter its letter label:\n");
    printf("a)Show number of empty seats\n");
    printf("b)Show list of empty seats\n");
    printf("c)Show alphabetical list of seats\n");
    printf("d)Assign a customer to a seat assignment\n");
    printf("e)Delete a seat assignment\n");
    printf("f)Quit\n");
}

char get_a(void)
{
    char choice[MAX];
    gets(choice);
    while((strchr("abcdef",choice[0]))==NULL)
    {
        printf("Wrong input! Input again:");
        gets(choice);
    }
    return choice[0];
}

int choose_a(int num,struct plane arr[num])
{
    int empty=0;
    for(int i=0;i<num;i++)
        if(arr[i].book==0)
            empty++;
    printf("The number of empty seats is %d.\n",empty);
    return empty;
}

void choose_b(int num,struct plane arr[num])
{
    printf("Here is the list:\n");
    for(int i=0;i<num;i++)
        if(arr[i].book==0)
            printf("seat: %d ",arr[i].number);
}

void choose_c(int num,struct plane arr[num])
{
    int count=0;
    printf("%-*s %-*s %s\n",LEN,"First name",LEN,"Last name","Number of seats");
    for(int i=0;i<num;i++)
        if(arr[i].book)
        {
            printf("%-*s %-*s %d\n",LEN,arr[i].f_name,LEN,arr[i].l_name,arr[i].number);
            count++;
        }
    if(count==0)
        printf("%-*s %-*s %s\n",LEN,"Nobody",LEN,"Nobody","None");
}

void choose_d(int num,struct plane (*arr)[num])
{
    int need;
    char answer[MAX];
    char name[2][LEN];
    printf("Please enter the number of seats:");
    while(1)
    {
        gets(answer);
        need=strtol(answer,NULL,10);
        if((need<1||need>SIZE)||(*arr)[need-1].book==1)
        {
            if((*arr)[need-1].book==1)
                printf("Already booked.Choose another one:");
            else
                printf("Wrong input.Again:");
        }
        else
            break;
    }
    (*arr)[need-1].book=1;
    printf("Please enter your first name:");
    s_gets(name[0],LEN);
    strncpy((*arr)[need-1].f_name,name[0],LEN);
    printf("Please enter your second name:");
    s_gets(name[1],LEN);
    strncpy((*arr)[need-1].l_name,name[1],LEN);
}

void choose_e(int num,struct plane (*arr)[num])
{
    int dele;
    char answer[MAX];
    printf("Please enter the number of your seat:");
    while(1)
    {
        gets(answer);
        dele=strtol(answer,NULL,10);
        if((dele<1||dele>SIZE)||(*arr)[dele-1].book==0)
        {
            if((*arr)[dele-1].book==1)
                printf("No booked.Input again:");
            else
                printf("Wrong input.Again:");
        }
        else
            break;
    }
    (*arr)[dele-1].book=0;
    strncpy((*arr)[dele-1].f_name,"\0",LEN);
    strncpy((*arr)[dele-1].l_name,"\0",LEN);
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
