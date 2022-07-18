#include <stdio.h>

int main() {
    int num;
    char signal;
    printf("please input a number\n");
    scanf("%d",&num);
    signal = num;
    printf("the character for %d is %c",signal,signal);
    return 0;
}
