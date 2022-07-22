#include <stdio.h>

void to_base_n(int,int);

int main() {
    int number,base;
    printf("Hello, please enter an integer and the base to convert to:\n");
    while(scanf("%d %d",&number,&base)==2)
    {
        to_base_n(number,base);
        printf("\n");
        printf("Hello, please enter an integer and the base to convert to:\n");
    }
    return 0;
}

void to_base_n(int num,int base)
{
    int left;
    left=num%base;
    if(num>base)
        to_base_n(num/base,base);
    else if(num==base)
        left=1;
    printf("%d",left);
}
