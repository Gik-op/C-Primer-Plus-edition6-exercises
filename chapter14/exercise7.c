/*从文件book.dat中读取每条记录并显示
 * 允许用户删除或修改记录的内容
 * 采用的方法是：改动存储在内存中的所有数据，再把最后的信息写入文件*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
#define MAX 256
char * s_gets(char *st,int n);
struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    int exist;//exist为1时存在，为0时可对其内容进行覆盖（重新读入）
};

int main()
{
    static struct book library[MAXBKS];//结构内的值全部初始化为0
    int count=0;
    int filecount;
    FILE *pbooks;
    int size = sizeof(struct book);
    char choice[MAX];

    if((pbooks=fopen("book.dat","r+b"))==NULL)
    {
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    rewind(pbooks);
    //读取文件中原本的内容并显示
    while(count<MAXBKS&&fread(&library[count],size,1,pbooks)==1)
    {
        if(count==0)
            puts("Current contents of book.dat:");
        printf("%d %s by %s: $%.2f\n",count+1,library[count].title,library[count].author,library[count].value);
        count++;
    }
    filecount=count;
    fclose(pbooks);
    //确定要删除的内容
    if(count!=0)
    {
        puts("Please enter the serial number of the book you want to delete(No to skip):");
        gets(choice);
        while(choice[0]!='N')
        {
            int aim;
            if(sscanf(choice,"%d",&aim)==1&&0<aim&&aim<=filecount)
            {
                library[aim-1].exist=0;//1为存在，0为不存在
                count--;//书籍数变化
                printf("Enter the next book you want to delete(No to skip):");
            }
            else
                printf("Wrong input! Input again:");
            gets(choice);
        }
    }
    if(count==MAXBKS)
    {
        fputs("The book.dat file is full.",stderr);
        exit(2);
    }
    //确定要添加的内容
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while(count<MAXBKS)
    {
        int empty=0;
        for(int i=0;i<MAXBKS;i++)
        {
            if(library[i].exist==0)
            {
                empty=i;//找到空出的结构块
                break;
            }
        }
        if(s_gets(library[empty].title,MAXTITL)!=NULL&&library[empty].title[0]!='\0')
        {
            puts("Now enter the author.");
            s_gets(library[empty].author,MAXAUTL);
            puts("Now enter the value.");
            scanf("%f",&library[empty].value);
            while(getchar()!='\n')
                continue;
            library[empty].exist=1;
            count++;
            if(count<MAXBKS)
                puts("Enter the next title.");
            else
                break;
        }
        else
            break;
    }
    //把内容写入文件
    if((pbooks=fopen("book.dat","w+b"))==NULL)
    {
        fputs("Can't write to book.dat file\n",stderr);
        exit(1);
    }
    if(count>0)
    {
        int rank=1;
        puts("Here is the list of your books:");
        rewind(pbooks);
        for(int i=0;i<MAXBKS;i++)
        {
            if(library[i].exist==1)
            {
                printf("%d %s by %s: $%.2f\n",rank,library[i].title,
                       library[i].author,library[i].value);
                fwrite(&library[i],size,1,pbooks);
                rank++;
            }
        }
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye.");
    fclose(pbooks);
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
