#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

#define LEFT 0
#define CENTER 1
#define RIGHT 2

#define size_move 8
#define mode_move 15
#define font_I_mask 255u
#define font_size_mask (127u<<size_move)
#define mode_align_mask (3u<<mode_move)
#define mode_B 0x20000
#define mode_I 0x40000
#define mode_U 0x80000

const char *mode[3]={"Left","Center","Right"};

char* valid_get(int num,char arr[num]);
void show_word(unsigned long set);
void menu(void);

void ch_font(unsigned long *pw);
void ch_size(unsigned long *pw);
void ch_align(unsigned long *pw);

int main()
{
    char choice[MAX];
    unsigned long font=1+(12<<size_move)+(0<<mode_move)+mode_B+mode_I+mode_U;//初始化
    do
    {
        show_word(font);
        menu();
        valid_get(MAX,choice);
        switch(choice[0])
        {
            case'f':
                ch_font(&font);
                break;
            case's':
                ch_size(&font);
                break;
            case'a':
                ch_align(&font);
                break;
            case'b':
                font^=mode_B;
                break;
            case'i':
                font^=mode_I;
                break;
            case'u':
                font^=mode_U;
                break;
            default:
                break;
        }
    }while(choice[0]!='q');
    printf("Bye.");
    return 0;
}

char* valid_get(int num,char arr[num])
{
    gets(arr);
    while((strchr("abiuqsf",arr[0]))==NULL)
    {
        printf("Invalid input.Input again:");
        gets(arr);
    }
    return arr;
}

void show_word(unsigned long set)
{
    printf("ID  SIZE ALIGNMENT   B   I   U\n");
    printf("%-3d %3d  %6s     %3s %3s %3s\n",set&font_I_mask,(set&font_size_mask)>>size_move,
          mode[(set&mode_align_mask)>>mode_move],(set&mode_B)==mode_B?"on":"off",
           (set&mode_I)==mode_I?"on":"off",(set&mode_U)==mode_U?"on":"off");//采用的数据读入方式是从右往左
}

void menu(void)
{
    printf("f)change font   s)change size   a)change alignment\n");
    printf("b)toggle bold   i)toggle italic u)toggle underline\n");
    printf("q)quit\n");
}

void ch_font(unsigned long *pw)
{
    unsigned long number;
    char content[MAX];
    while(1)
    {
        printf("Enter font ID(0-255):");
        gets(content);
        number=strtol(content,NULL,10);
        if(number>255||(number<0||(content[0]!='0'&&number==0)))
            printf("Invalid input.\n");
        else
            break;
    }
    *pw=(*pw&(~font_I_mask))^(number&font_I_mask);
}

void ch_size(unsigned long *pw)
{
    unsigned long number;
    char yours[MAX];
    while(1)
    {
        printf("Enter font ID(0-127):");
        gets(yours);
        number=strtol(yours,NULL,10);
        if(number>127||(number<0||(yours[0]!='0'&&number==0)))
            printf("Invalid input.\n");
        else
            break;
    }
    number<<=size_move;
    *pw=(*pw&(~font_size_mask))^(number&font_size_mask);
}

void ch_align(unsigned long *pw)
{
    char yours[MAX];
    printf("Select alignment:\n");
    printf("l)left  c)center  r)right\n");
    gets(yours);
    while((strchr("lcrLCR",yours[0]))==NULL)
    {
        printf("Invalid input.\n");
        gets(yours);
    }
    switch(yours[0])
    {
        case'c':
        case'C':*pw=(*pw&(~mode_align_mask))^(CENTER<<mode_move);break;
        case'r':
        case'R':*pw=(*pw&(~mode_align_mask))^(RIGHT<<mode_move);break;
        case'l':
        case'L':*pw=(*pw&(~mode_align_mask))^(LEFT<<mode_move);break;
    }
}