#include <stdio.h>
#include <math.h>

int main()
{
    int term,input;
    printf("Hello, this one is used to sum over infinite sequence!\n");
    printf("Please enter the number of terms you want to sum:");
    input = scanf("%d",&term);
    while(input==1&&term>0)
    {
        term-=1;//下面的sum已经包括了第一项
        double sum1=1.0,sum2=1.0;
        double first=2.0;
        printf("The result of the first sequence");//1.0+1.0/2.0+1.0/3.0......
        for(int con=0;con<term;con++)
        {
            sum1+=1.0/first;
            first++;
        }
        printf("is %.6f\n",sum1);
        printf("The result of the second sequence");//1.0-1.0/2.0+1.0/3.0-1.0/4.0......
        first=2.0;
        for(int con=0;con<term;con++)
        {
            sum2+=(1.0/first)*pow(-1.0,first+1.0);
            first++;
        }
        printf("is %.6f\n",sum2);
        printf("Please enter the number of terms you want to sum(q to quit):");
        input = scanf("%d",&term);
    }
    printf("Done!");
    return 0;
}
