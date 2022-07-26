#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

int main()
{
    int num;
    char choice[MAX];
    printf("How many words do you wish to enter?");
    gets(choice);
    while(sscanf(choice,"%d",&num)==1)
    {
        printf("Enter %d words now:\n",num);
        int count=0;//计算单词数
        unsigned long long limit,pos=0;
        char *seek;
        char temp[MAX];
        char **my_word = (char **)malloc(num*sizeof(char*));
        gets(temp);
        seek=temp;
        limit=strlen(temp);
        while(pos<limit)/*注意：这里不能采用指针，采用指针可能在循环内部跳过空字符，因此只能用字符串长度限制*/
        {
            int size=0;
            char *ptr;
            while(!isalnum(*seek))
            {
                seek++;
                pos++;
            }
            ptr=seek;//记录单词首字母开始的位置
            while(!isspace(*seek)&&!ispunct(*seek))
            {
                size++;//计算单词所需的内存空间的大小
                seek++;
                pos++;
            }//一个单词结束
            my_word[count]=(char *)malloc((size+1)*sizeof(char));//给单词赋予恰到好处的内存空间
            strncpy(my_word[count],ptr,size);//拷贝单词进入内存空间(好像还要加一个字符串结束的空字符啊......)
            my_word[count][size]='\0';//没事，空字符自个儿加
            count++;
            if(count>=num)//处理输入数组中单词数超出的情况
                break;
        }
        printf("Here are your words:\n");
        for(int i=0;i<count;i++)//打印单词
            printf("%s\n",my_word[i]);
        for(int n=0;n<count;n++)
            free(my_word[n]);//依次释放内存空间
        free(my_word);
        printf("How many words do you wish to enter(q to stop):");
        gets(choice);
    }
    printf("Thanks for using.");
    return 0;
}
