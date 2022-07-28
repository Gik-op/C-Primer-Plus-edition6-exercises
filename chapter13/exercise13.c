#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main()
{
    char name[MAX];
    int LINE,ROW,line=0,row=0;
    FILE *fp;
    printf("Hello, please enter the name of the file:");
    gets(name);
    if((fp=fopen(name,"r+"))==NULL)
    {
        printf("Can't open the file %s.\n",name);
        exit(1);
    }
    printf("Please enter the line and row of the numbers(eg.6 8):");
    while(scanf("%d %d",&LINE,&ROW)!=2)
    {
        while(getchar()!='\n')
            continue;
        printf("Wrong input! Input again(eg. 6 8):");
    }
    int number[LINE][ROW];
    char num[LINE][ROW+1];
    //处理某行数字减少或超出的情况
    //为提高程序鲁棒性，考虑一行一行地读数，舍弃掉多余的数，并且把没有读到的数用0补全
    //再考虑行数不够的情况，行数不够时，剩余数字用0补全
    while(line<LINE)
    {
        char aline[MAX];
        char *ptr=aline;
        if((fgets(aline,MAX,fp))!=NULL)//对一行进行处理
        {
            while(*ptr&&row<ROW)
            {
                if(*ptr>='0'&&*ptr<='9')
                {
                    number[line][row]=*ptr-48;
                    row++;
                }
                ptr++;
            }
            if(row<ROW)
            {
                for(int i=row;i<ROW;i++)
                    number[line][i]=0;
            }
        }
        else
            for(;row<ROW;row++)
                number[line][row]=0;
        row=0;
        line++;
    }
    for(int n=0;n<LINE;n++)
    {
        for(int k=0;k<ROW;k++)
        {
            switch(number[n][k])
            {
                case 0:num[n][k]=' ';break;
                case 1:num[n][k]='.';break;
                case 2:num[n][k]='\'';break;
                case 3:num[n][k]=':';break;
                case 4:num[n][k]='~';break;
                case 5:num[n][k]='*';break;
                case 6:num[n][k]='=';break;
                case 7:num[n][k]=' ';break;
                case 8:num[n][k]='%';break;
                case 9:num[n][k]='#';break;
            }
        }
        num[n][ROW]='\0';
    }//字符串赋值
    fseek(fp,0L,SEEK_END);
    fprintf(fp,"\n");
    for(int c=0;c<LINE;c++)
        fprintf(fp,"%s\n",num[c]);
    fclose(fp);
    printf("Done!");
    return 0;
}