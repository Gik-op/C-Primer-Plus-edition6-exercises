#include <stdio.h>
#include <string.h>

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

int main()
{
    char choice[MAX];
    /*printf("Hello, please enter the name of a month:\n");
    gets(choice);*/
    do
    {
        int number=0,total=0,i=0;
        printf("Hello, please enter the name of a month\n(press [enter] to stop):");
        gets(choice);
        while(i<12)
        {
            if(!strcmp(choice,MONTH[i].month)||!strcmp(choice,MONTH[i].s_name))
            {
                number=MONTH[i].rank;
                break;
            }
            i++;
        }
        if(number>0)
        {
            for(int count=0;count<number;count++)
                total+=MONTH[count].days;
            printf("The total number of days until %s is %d.\n",MONTH[number-1].month,total);
        }
        else if(choice[0])
            printf("Can't find month %s!\n",choice);
    } while(choice[0]);
    printf("Done!");
    return 0;
}
