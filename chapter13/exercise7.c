#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    FILE *first,*second;
    char file1[SIZE],file2[SIZE],choice[SIZE];
    printf("Hello, please enter the name of the first file:");
    gets(file1);
    if((first=fopen(file1,"r"))==NULL)
    {
        printf("Can't open the file %s.\n",file1);
        exit(EXIT_FAILURE);
    }
    printf("Please enter the name of the second file:");
    gets(file2);
    if((second=fopen(file2,"r"))==NULL)
    {
        printf("Can't open the file %s.\n",file1);
        exit(EXIT_FAILURE);
    }
    printf("Please choose the print mode(1 or 2).\n");
    gets(choice);
    while(choice[0]=='1')
    {
        char sent1[SIZE];
        char sent2[SIZE];
        int label1=0,label2=0;
        if(fgets(sent1,SIZE,first)!=NULL)
        {
            fputs(sent1,stdout);
            label1=1;
        }
        if(fgets(sent2,SIZE,second)!=NULL)
        {
            fputs(sent2,stdout);
            label2=1;
        }
        if(label1+label2==0)
            break;
    }
    if(choice[0]=='2')
    {
        char sent1[SIZE][SIZE];
        char sent2[SIZE][SIZE];
        int count1=0,count2=0;
        while(fgets(sent1[count1],SIZE,first)!=NULL)
            count1++;
        while(fgets(sent2[count2],SIZE,second)!=NULL)
            count2++;
        for(int i=0;i<max(count1,count2);i++)
        {
            if(i<count2&&i<count1)
            {
                char *find;
                find=strchr(sent1[i],'\n');
                *find=' ';
                *(find+1)='\0';
            }//处理同一行的问题
            fputs(sent1[i],stdout);
            fputs(sent2[i],stdout);
        }
    }
    printf("\nDone!");
    return 0;
}
