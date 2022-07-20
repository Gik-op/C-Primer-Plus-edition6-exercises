#include <stdio.h>

int main()
{
    char ch;
    char prev=' ';
    int count=0;
    printf("Please enter something!\n");
    while((ch=getchar())!='#')
    {
        if(prev=='e'&&ch=='i')
            count++;
        prev=ch;
    }
    printf("There are %d \"ei\".\n",count);
    return 0;
}
