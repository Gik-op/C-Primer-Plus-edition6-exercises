#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define OPEN 1
#define CLOSE 0
#define ID_mask 255
#define SIZE_mask 127

#define MAX 256

struct word{
    unsigned int ID:8;
    unsigned int size:7;
    unsigned int Alignment:2;
    unsigned int B:1;
    unsigned int I:1;
    unsigned int U:1;
};

const char *mode[3]={"Left","Center","Right"};

char* valid_get(int num,char arr[num]);
void show_word(const struct word *pw);
void menu(void);

void ch_font(struct word *pw);
void ch_size(struct word *pw);
void ch_align(struct word *pw);

int main()
{
    char choice[MAX];
    struct word font={1,12,LEFT,CLOSE,CLOSE,CLOSE};
    do
    {
        show_word(&font);
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
                font.B^=OPEN;
                break;
            case'i':
                font.I^=OPEN;
                break;
            case'u':
                font.U^=OPEN;
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

void show_word(const struct word *pw)
{
    printf("ID  SIZE ALIGNMENT   B   I   U\n");
    printf("%-3d %3d  %6s     %3s %3s %3s\n",pw->ID,pw->size,
           mode[pw->Alignment],pw->B?"on":"off",pw->I?"on":"off",pw->U?"on":"off");
}

void menu(void)
{
    printf("f)change font   s)change size   a)change alignment\n");
    printf("b)toggle bold   i)toggle italic u)toggle underline\n");
    printf("q)quit\n");
}

void ch_font(struct word *pw)
{
    int number;
    char content[MAX];
    do{
        printf("Enter font ID(0-255):");
        gets(content);
        number=strtol(content,NULL,10);
    }while(number>255||number<0);
    pw->ID=number&ID_mask;
}

void ch_size(struct word *pw)
{
    int number;
    char yours[MAX];
    do{
        printf("Enter font size(0-127):");
        gets(yours);
        number=strtol(yours,NULL,10);
    }while(number>127||number<0);
    pw->size=number&SIZE_mask;
}

void ch_align(struct word *pw)
{
    char yours[MAX];
    printf("Select alignment:\n");
    printf("l)left  c)center  r)right\n");
    gets(yours);
    while((strchr("lcrLCR",yours[0]))==NULL)
    {
        printf("Invalid input.Input again(l:left c:center r:right):");
        gets(yours);
    }
    switch(yours[0])
    {
        case'c':
        case'C':pw->Alignment=CENTER;break;
        case'r':
        case'R':pw->Alignment=RIGHT;break;
        case'l':
        case'L':pw->Alignment=LEFT;break;
    }
}

