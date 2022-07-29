#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definition.h"

void menu(int num)
{
    printf("\nThe flight %d.\n",num);
    printf("To choose a function, enter its letter label:\n");
    printf("a)Show number of empty seats\n");
    printf("b)Show list of empty seats\n");
    printf("c)Show alphabetical list of seats\n");
    printf("d)Assign a customer to a seat assignment\n");
    printf("e)Delete a seat assignment\n");
    printf("f)Quit\n");
    printf("g)Confirm seat assignment\n");
}

char get_a(void)
{
    char choice[MAX];
    gets(choice);
    while((strchr("abcdefg",choice[0]))==NULL)
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
    printf("%-*s %-*s %5s %12s\n",LEN,"First name",LEN,"Last name","Seats","Confirmed");
    for(int i=0;i<num;i++)
        if(arr[i].book)
        {
            printf("%-*s %-*s %-5d %8s\n",LEN,arr[i].f_name,LEN,arr[i].l_name,
                   arr[i].number,arr[i].confirm==true?"Yes":"No");
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

void choose_g(int num,struct plane (*arr)[num])
{
    int seat;
    char answer[MAX];
    printf("Please enter the number of the seat you want to confirm:");
    while(1)
    {
        gets(answer);
        seat=strtol(answer,NULL,10);
        if((seat<1||seat>SIZE)||(*arr)[seat-1].book==0)
        {
            if((*arr)[seat-1].book==0)
                printf("No booked.Input again:");
            else
                printf("Wrong input.Again:");
        }
        else
            break;
    }
    (*arr)[seat-1].confirm=true;
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
