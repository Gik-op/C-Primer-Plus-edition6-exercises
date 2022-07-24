#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 256

bool is_within(char,char*);

int main() {
    char test[MAX],aim[MAX];
    bool answer;
    printf("Please enter a character.\n");
    gets(aim);
    do
    {
        printf("\nPlease enter a sentence, \n"
               "and I'll check whether there are %c in it.\n",aim[0]);
        gets(test);
        answer=is_within(aim[0],test);
        if(answer)
            printf("Hey,you get %c in your sentence!\n",aim[0]);
        else
            printf("Oh no, I can't find it.\n");
    }while(answer);
    printf("Bye.\n");
    return 0;
}

bool is_within(char aim,char* arr)
{
    unsigned long long size;
    bool judge=false;
    size=strlen(arr);
    for(int i=0;i<size;i++)
    {
        if(*(arr+i)==aim)
        {
            judge=true;
            break;
        }
    }
     return judge;
}
