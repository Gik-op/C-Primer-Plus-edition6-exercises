#ifndef UNIT17EXER5_STACK_H
#define UNIT17EXER5_STACK_H

#include <stdbool.h>

//The difinition of the stack

typedef char Item;

struct node{
    Item alfa;
    struct node *prev;
};
typedef struct node Node;

typedef struct stack{
    Node *tail;
    unsigned int size;
}Stack;

//The function of the stack

void Initialization(Stack *st);

bool StackIsEmpty(const Stack *st);
bool StackIsfull(const Stack *st);

unsigned int CountNode(const Stack *st);

bool AddNode(Item item,Stack *st);
void DeleteNode(Stack *st);
void ShowNode(const Stack *st,void(*pfun)(Node item));

void EmptyNode(Stack *st);

#endif //UNIT17EXER5_STACK_H
