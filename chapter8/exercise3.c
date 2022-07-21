#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;
    int upper=0,lower=0;
    while((ch=getchar())!=EOF)
    {
        if(isupper(ch))
           upper++;
        if(islower(ch))
            lower++;
    }
    printf("Hello, there are %d capital letter, %d small letter!\n",upper,lower);
    return 0;
}
