#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    int flag=0;
    unsigned long long word_n=0,count_A=0,count_a=0,count_i=0,sign_n=0;
    while((ch=getchar())!=EOF)
    {
        if(!isspace(ch)&&!ispunct(ch)&&flag==0)//这里一串数字也被看作单词，
        {                                            // 如果不想把数字计数成单词，可添加对isdigit()的条件判断
            flag=1;
            word_n++;
        }
        if((isspace(ch)|| ispunct(ch))&&flag==1)//单词计数
            flag=0;
        if(isupper(ch))
            count_A++;
        else if(islower(ch))
            count_a++;
        else if(isdigit(ch))
            count_i++;
        else if(ispunct(ch))
            sign_n++;
    }
    printf("Hello, in the article:\n words %ld\n capital letter %ld\n small letter %ld\n"
           " punctuation %ld\n number %ld\n",word_n,count_A,count_a,sign_n,count_i);
    getchar();
    return 0;
}
