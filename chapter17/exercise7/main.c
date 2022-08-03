#include "tree.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 256

char menu(void);
void ReadtheWord(FILE *fp,Tree *base);
void show_item(Trnode trnode);

int main()
{
    FILE *fp;
    char choice;
    Tree words;
    InitializeTree(&words);
    if((fp=fopen("song_1.txt","r+"))==NULL)
    {
        printf("Can't open the file %s.\n","song_1.txt");
        exit(EXIT_FAILURE);
    }
    ReadtheWord(fp,&words);
    choice=menu();
    while(choice!='q')
    {
        if(choice=='a')
        {
            Traverse(&words, show_item);
        }
        else if(choice=='b')
        {
            char word[MAX];
            Item item;
            Trnode *find;
            puts("Please enter the word you seek:");
            gets(word);
            strncpy(item.word,word,SLEN);
            find=SeekItem(&item,&words).child;
            if(find!=NULL)
                printf("Word: %s\nOccurrence number: %d\n", find->item,find->times);
            else
                printf("Can't find %s\n",word);

        }
        choice=menu();
    }
    DeleteAll(&words);
    printf("Bye.");
    return 0;
}

char menu(void)
{
    char input[MAX];
    puts("To choose a function,please enter its letter label:");
    puts("a)List all the words and the number of times they appear");
    puts("b)Find the number of occurrences of a word");
    puts("q)quit");
    gets(input);
    while(strchr("abq",input[0])==NULL)
    {
        puts("Wrong input! Input a,b or q.");
        gets(input);
    }
    return input[0];
}

void ReadtheWord(FILE *fp,Tree *base)
{
    char ch;
    char word[SLEN];//The maximum size of a single word is 20
    int index=0,label=0;//label marks the beginning of a word
    while((ch=getc(fp))!=EOF)
    {
        if(isalnum(ch))
        {
            if(label==0)
                label=1;
            word[index]=ch;
            index++;
        }
        if((ispunct(ch)|| isspace(ch))&&label==1)
        {
            word[index]='\0';
            label=0;
            index=0;
            Item item;
            strncpy(item.word,word,SLEN);
            AddItem(&item,base);
        }
    }
}

void show_item(Trnode trnode)
{
    printf("%15s %3d\n",trnode.item,trnode.times);
}
