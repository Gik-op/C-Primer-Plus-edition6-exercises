#include <stdio.h>

char getRes(void);

int main()
{
    char re;
    int guess=50;
    int top=100,low=0;
    printf("Hello, please pick an integer from 1 to 100. I'll guess it!\n");
    printf("Respond with a \'s\' if my guess is smaller than your integer\n and with a "
           "\'b\' if it is bigger.\nIf my guess right, please respond with a \'y\'.\n");
    printf("Uh...is your number %d?\n",guess);
    re = getRes();
    while(re!='y')
    {
        if(re=='s')
            low=guess;
        else
            top=guess;
        guess=(low+top)/2;
        printf("Uh...is your number %d?\n",guess);
        re = getRes();
    }
    printf("Yes I get it!——%d",guess);
    return 0;
}

char getRes(void)
{
    char res;
    res=getchar();
    while(res!='y'&&res!='s'&&res!='b')
    {
        fflush(stdin);
        printf("Wrong input! Please enter again.\n(s for smaller, b for bigger,y for right)\n");
        res=getchar();
    }
    fflush(stdin);
    return res;
}