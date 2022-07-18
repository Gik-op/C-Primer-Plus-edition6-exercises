#include <stdio.h>
#define M2H 60

int main()
{
    int min,hour,left,input;
    printf("Hello, give me the number of minutes:\n");
    input=scanf("%d",&min);
    while(input==1&&min>0)
    {
        hour=min/M2H;
        left=min%M2H;
        printf("%d minutes is %d hour, %d minutes.\n",min,hour,left);
        printf("Hello, give me the number of minutes(enter 0 to end):\n");
        input=scanf("%d",&min);
    }
    printf("Done! Wish you a nice time!");
    return 0;
}
