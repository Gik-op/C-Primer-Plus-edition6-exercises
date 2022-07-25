#include <stdio.h>

int main(int argc,char *argv [])
{
    printf("Now I will display cmd arguments in reverse order.\n");
    for(int count=0;count<argc-1;count++)//减1是为了避免将程序本身的名称读入
    {
        printf("%s ",argv[argc-count-1]);
    }
    printf("\nDone!\n");
    return 0;
}
