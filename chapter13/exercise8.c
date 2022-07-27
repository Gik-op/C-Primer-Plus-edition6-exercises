#include <stdio.h>

int main(int argc,char *argv [])//无响应
{
    int files=2;
    FILE *fp;
    if(argc<2)
        printf("No enough parameter!\n");
    else if(argc==2)
    {
        printf("Please enter something,and I'll count the number of %c\n(EOF to stop)\n",argv[1][0]);
        int count=0,ch;
        while((ch=getchar())!=EOF)
        {
            if(ch==argv[1][0])
                count++;
        }
        if(count!=0)
            printf("There %s %d %c.",count>1?"are":"is",count,argv[1][0]);
        else
            printf("No %c.",argv[1][0]);
    }
    else
    {
        while(files<argc)
        {
            int count=0,ch;
            if((fp=fopen(argv[files],"r"))==NULL)
            {
                printf("Can't open the file %s!\n",argv[files]);
                continue;
            }
            while((ch=getc(fp))!=EOF)
            {
                if(ch==argv[1][0])
                    count++;
            }
            fclose(fp);
            if(count!=0)
                printf("In file %s, there %s %d %c.",argv[files],count>1?"are":"is",count,argv[1][0]);
            else
                printf("In file %s, no %c.",argv[files],argv[1][0]);
            files++;
        }
    }
    printf("\nDone!\n");
    return 0;
}
