#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIM 10
#define SIZE 256

void menu(void);
void show(int line,int row,char arr[line][row]);
void rank_a(int line,char *strings []);//按ASCII码排序
void rank_l(int line,char *strings []);//按长度排序
void rank_f(int line,char *strings []);//按首单词长度

int get_word(char *array);//计算首单词的长度

int main()
{
    char input[LIM][SIZE];
    char choice[SIZE];
    char *ptr_input [LIM];
    int count=0;
    printf("Please enter up to %d strings.\n",LIM);
    while(count<LIM)
    {
        gets(input[count]);
        ptr_input[count]=input[count];
        count++;
    }
    do
    {
        menu();
        gets(choice);
        switch(choice[0])
        {
            case'a':show(LIM,SIZE,input);break;
            case'b':rank_a(LIM,ptr_input);break;
            case'c':rank_l(LIM,ptr_input);break;
            case'd':rank_f(LIM,ptr_input);break;
            case'q':break;
            default:printf("Wrong input!\n");break;
        }
    }while(choice[0]!='q');
    printf("Bye.\n");
    return 0;
}

void menu(void)
{
    printf("Enter the operation of your choice:\n");
    printf("a) show the strings  b) print strings in ASCII sequence\n");
    printf("c) print strings in increasing length order\n");
    printf("d) print by the length of the first word in the string\n");
    printf("q) quit\n");
}

void show(int line,int row,char arr[line][row])
{
    for(int l=0;l<line;l++)
        printf("%s\n",arr[l]);
}

void rank_a(int line,char *strings [])
{
    char *temp;
    for(int top=0;top<line-1;top++)
        for(int seek=top+1;seek<line;seek++)
            if(strcmp(strings[top],strings[seek])>0)//调换字符串指针的位置（逆序）返回正数
            {
                temp=strings[top];
                strings[top]=strings[seek];
                strings[seek]=temp;
            }
    for(int k=0;k<line;k++)
        puts(strings[k]);
}

void rank_l(int line,char *strings [])
{
    char *ptr;
    for(int top=0;top<line-1;top++)
        for(int seek=top+1;seek<line;seek++)
        {
            if(strlen(strings[top])> strlen(strings[seek]))
            {
                ptr=strings[top];
                strings[top]=strings[seek];
                strings[seek]=ptr;
            }
        }
    for(int k=0;k<line;k++)
        puts(strings[k]);

}

void rank_f(int line,char *strings [])
{
    char *ptr;
    for(int top=0;top<line-1;top++)
        for(int seek=top+1;seek<line;seek++)
        {
            if(get_word(strings[top])> get_word(strings[seek]))
            {
                ptr=strings[top];
                strings[top]=strings[seek];
                strings[seek]=ptr;
            }
        }
    for(int k=0;k<line;k++)
        puts(strings[k]);
}

int get_word(char *array)
{
    char *ptr=array;
    int count=0;
    while(isspace(*ptr++));
    while(!isspace(*ptr)&&(*ptr!='\0'))
    {
        count++;
        ptr++;
    }
    return count;
}



