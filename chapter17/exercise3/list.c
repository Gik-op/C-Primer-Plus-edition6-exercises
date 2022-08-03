/* list.c -- functions supporting list operations */
#include "list.h"

static void CopyToNode(Item item,List *plist);
static Item initialization={
        "\0",0
};

void InitializeList(List *plist)
{
    plist->entries[0]=initialization;
    plist->items = 0;
}

/*preconditions: ：plist points to an initialized list */

bool ListIsEmpty(const List * plist)
{
    if (plist->items == 0)
        return true;
    else
        return false;
}

bool ListIsFull(const List *plist)
{
    bool full;
    if (plist->items == MAXSIZE)
        full = true;
    else
        full = false;
    return full;
}

unsigned int ListItemCount(const List * plist)
{
    return plist->items;
}

bool AddItem(Item item, List * plist)
{
    if (plist->items == MAXSIZE)
        return false;
    CopyToNode(item, plist);
    plist->items++;
    return true;
}

void Traverse  (const List * plist, void (* pfun)(Item item) )
{
    int index=0;
    while (index < plist->items)
    {
        (*pfun)(plist->entries[index]);
        index++;
    }
}

void EmptyTheList(List * plist)
{
    int index=0;
    while (index < plist->items)
    {
        plist->entries[index]=initialization;
        index++;
    }
}

static void CopyToNode(Item item, List *plist)
{
    plist->entries[plist->items]=item;
}
