#include <stdio.h>
#define MAX 256

int main()
{
    char ch;
    char cha[MAX];
    int count=0;
    printf("Please enter something you like.\n");
    while((ch=getchar())!=EOF)
    {
        cha[count]=ch;
        count++;
    }
    for(int con=0;con<=count;con++)
    {
        if(cha[con]=='\n')
            printf("\\n:%-3d",cha[con]);
        else if(cha[con]=='\t')
            printf("\\t:%-3d",cha[con]);
        else if((int)cha[con]<32)
            printf("^%c:%-3d",cha[con]+64,cha[con]);
        else
            printf("%c:%-4d",cha[con],cha[con]);
        if((con+1)%10==0)
            printf("\n");
    }
    printf("\nFinished!\n");
    getchar();
    return 0;
}
