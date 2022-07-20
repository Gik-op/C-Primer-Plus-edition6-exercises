#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    char ch;
    long n_char = 0L;
    int n_space = 0;
    int n_lines = 0;
    int n_word = 0;
    bool inword = false;
    printf("Please enter a text(# to terminate):\n");
    while((ch=getchar())!='#')
    {
        n_char++;
        if(!isspace(ch)&&!inword)
        {
            inword=true;
            n_word++;
        }
        if(isspace(ch)&&ch!='\n')
            n_space++;
        else if(ch=='\n')
            n_lines++;
        if(isspace(ch)&&inword)
            inword=false;
    }
    printf("There are %d characters, %d words, %d space, %d lines.\n",n_char,n_word,n_space,n_lines);
    return 0;
}
