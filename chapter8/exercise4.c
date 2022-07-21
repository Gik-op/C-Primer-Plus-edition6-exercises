#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    int inword=0,count=0;//标记单词并对单词数进行计数
    long number=0;//对所有字母进行计数
    printf("Please enter something.(EOF to end)\n");
    while((ch=getchar())!=EOF)
    {
        if(isalpha(ch))
        {
            number++;//对字母计数
            if(inword==0)
            {
                inword=1;
                count++;//对单词计数
            }
        }
        else
            inword=0;
    }
    printf("Hello, there are %ld letters, %d words.\n"
           "In average, a word has %d letters. \n",number,count,number/count);
    getchar();
    return 0;
}
