#include <stdio.h>
#include "stack.h"

void show_ch(Node item)
{
    putchar(item.alfa);
}

int main()
{
    char ch;
    Stack my_stack;
    Initialization(&my_stack);
    puts("Hello, please enter a string:");
    while((ch=getchar())!='\n')
        AddNode(ch,&my_stack);
    printf("The number of characters in your string:%u\n", CountNode(&my_stack));
    puts("Your string displaying in inverted order:");
    ShowNode(&my_stack,show_ch);
    EmptyNode(&my_stack);
    return 0;
}
