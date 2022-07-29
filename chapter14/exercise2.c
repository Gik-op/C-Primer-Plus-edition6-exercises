#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 40
#define MAX 256

struct info{
    char month[LEN];
    char s_name[LEN];
    int days;
    int rank;
};

struct info MONTH[12]={
        {"January","Jan",31,1},
        {"February","Feb",28,2},
        {"March","Mar",31,3},
        {"April","Apr",30,4},
        {"May","May",31,5},
        {"June","Jun",30,6},
        {"July","Jul",31,7},
        {"August","Aug",31,8},
        {"September","Sep",30,9},
        {"October","Oct",31,10},
        {"November","Nov",30,11},
        {"December","Dec",31,12},
};

void special_year(struct info *fp,int year);
int get_num(int min,int max);

int main()
{
    int day,month=0,year;
    int total=0;
    char choice[MAX];
    struct info *special=&MONTH[1];
    printf("Hello,please enter the year you are looking for:");
    year=get_num(1000,3000);
    printf("Then input the month(eg January/Jan/1):");
    do
    {
        int i=0;
        gets(choice);
        while(i<12)
        {
            if(!strcmp(choice,MONTH[i].month)||!strcmp(choice,MONTH[i].s_name)||atoi(choice)==MONTH[i].rank)
            {
                month=MONTH[i].rank;
                break;
            }
            i++;
        }
        if(month==0)
            printf("Wrong input!Input again!\n");
    }while(month==0);
    special_year(special,year);
    printf("Finally,input the day of %s:",MONTH[month-1].s_name);
    day=get_num(1,MONTH[month-1].days);
    for(int count=0;count<month-1;count++)
        total+=MONTH[count].days;
    total+=day;
    printf("The total number of days is %d.\n",total);
    return 0;
}

void special_year(struct info *fp,int year)
{
    if((year%100!=0&&year%4==0)||(year%400==0))
        fp->days=29;
    else
        fp->days=28;
}

int get_num(int min,int max)
{
    int input;
    while((scanf("%d",&input))!=1||(input<min||input>max))
    {
        while(getchar()!='\n')
            continue;
        printf("Wrong input!Input again!\n");
    }
    while(getchar()!='\n')//想办法优化
        continue;
    return input;
}
