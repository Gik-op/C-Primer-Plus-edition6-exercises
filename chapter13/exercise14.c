#include <stdio.h>
#include <stdlib.h>

#define MAX 256

void handle(int line,int row,int arr[line][row]);

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
    handle(LINE,ROW,number);
    for(int n=0;n<LINE;n++)
    {
        for(int k=0;k<ROW;k++)
        {
            switch(number[n][k])
            {
                case 0:num[n][k]='0';break;//' ';break;
                case 1:num[n][k]='1';break;//'.';break;
                case 2:num[n][k]='2';break;//'\'';break;
                case 3:num[n][k]='3';break;//':';break;
                case 4:num[n][k]='4';break;//'~';break;
                case 5:num[n][k]='5';break;//'*';break;
                case 6:num[n][k]='6';break;//'=';break;
                case 7:num[n][k]='7';break;//' ';break;
                case 8:num[n][k]='8';break;//'%';break;
                case 9:num[n][k]='9';break;//'#';break;
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

void handle(int line,int row,int arr[line][row])
{
    for(int l=0;l<line;l++)
    {
        for(int r=0;r<row;r++)
        {
            int left=0,right=0,up=0,down=0;
            int label=0;//标记周围相邻点的个数
            if(r-1>=0)
            {
                left=arr[l][r]-arr[l][r-1];
                label++;
            }
            if(r+1<row)
            {
                right=arr[l][r]-arr[l][r+1];
                label++;
            }
            if(l-1>=0)
            {
                up=arr[l][r]-arr[l-1][r];
                label++;
            }
            if(l+1<line)
            {
                down=arr[l][r]-arr[l+1][r];
                label++;
            }
            if((abs(right)+abs(left)+abs(up)+abs(down))>label)
                arr[l][r]-=(right+left+up+down)/label;
        }
    }
}
