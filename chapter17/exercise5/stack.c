#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void Initialization(Stack *st)
{
    st->tail=NULL;
    st->size=0;
}

bool StackIsEmpty(const Stack *st)
{
    if(st->size==0)
        return true;
    else
        return false;
}

bool StackIsfull(const Stack *st)
{
    Node *new;
    new=(Node *)malloc(sizeof(Node));
    if(new==NULL)
        return true;
    else
        free(new);
    return false;
}

unsigned int CountNode(const Stack *st)
{
    return st->size;
}

bool AddNode(Item item,Stack *st)
{
    Node *new;
    new=(Node *)malloc(sizeof(Node));
    if(new==NULL)
    {
        fputs("Can't add new item!",stderr);
        return false;
    }
    new->alfa=item;
    new->prev=st->tail;
    st->tail=new;
    st->size++;
    return true;
}

void DeleteNode(Stack *st)
{
    Node *left;
    if(StackIsEmpty(st))
    {
        fputs("No items in stack!",stderr);
        return;
    }
    left=st->tail;
    st->tail=st->tail->prev;
    free(left);
}
void ShowNode(const Stack *st,void(*pfun)(Node item))
{
    Node *scan;
    scan=st->tail;
    while(scan!=NULL)
    {
        pfun(*scan);
        scan=scan->prev;
    }
}

void EmptyNode(Stack *st)
{
    Node *scan,*now;
    scan=st->tail;
    while(scan!=NULL)
    {
        now=scan;
        scan=scan->prev;
        free(now);
        st->size--;
    }
    st->tail=NULL;
}


