/* tree.c -- tree support functions */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* protototypes for local functions */
static Trnode * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode (Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * root, void (* pfun)(Trnode trnode));
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode * ptr);

/* function definitions */
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

Pair SeekName(const Item * pi, const Tree * ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
        return look;                        /* early return   */

    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item[0])))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item[0])))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else       /* must be same if not to left or right    */
            break; /* look.child is address of node with item */
    }

    return look;                       /* successful return   */
}

bool TreeIsEmpty(const Tree * ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * ptree)
{
    if (ptree->size == MAXITEMS*KIND)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode * new_node;
    Pair find=SeekName(pi, ptree);
    if  (TreeIsFull(ptree))
    {
        fprintf(stderr,"Tree is full\n");
        return false;             /* early return           */
    }
    if (InTree(pi,ptree))
    {
        fprintf(stderr,"Tree already has it.\n");
        return false;             /* early return           */
    }
    if (find.child != NULL)
    {
        if(find.child->index==KIND)
        {
            fprintf(stderr,"Couldn't add new pet\n");
            return false;
        }
        find.child->item[find.child->index]=*pi;
        find.child->index++;
    }
    else
    {
        new_node = MakeNode(pi);      /* points to new node     */
        if (new_node == NULL)
        {
            fprintf(stderr, "Couldn't create node\n");
            return false;             /* early return           */
        }
        /* succeeded in creating a new node */
        if (ptree->root == NULL)      /* case 1: tree is empty  */
            ptree->root = new_node;   /* new node is tree root  */
        else                          /* case 2: not empty      */
            AddNode(new_node,ptree->root); /* add node to tree  */
    }
    ptree->size++;//所有新加入的宠物都算入size中
    return true;                  /* successful return      */
}

bool InTree(const Item * pi, const Tree * ptree)
{
    Pair find=SeekName(pi, ptree);
    if(find.child != NULL)
    {
        for(int i=0;i<find.child->index;i++)
            if(strcmp(find.child->item[i].petkind,pi->petkind)==0)
                return true;
    }
    return false;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
    Pair look;
    if (!InTree(pi,ptree))
        return false;
    look = SeekName(pi, ptree);
    if (look.child->index==1)
    {
        if (look.parent == NULL)      /* delete root item       */
            DeleteNode(&ptree->root);
        else if (look.parent->left == look.child)
            DeleteNode(&look.parent->left);
        else
            DeleteNode(&look.parent->right);
    }
    else
    {
        int label;
        for(int i=0;i<look.child->index;i++)
        {
            if(strcmp(look.child->item[i].petkind,pi->petkind)==0)
            {
                label=i;
                look.child->index--;
            }
            if(i>=label)
                look.child->item[i]=look.child->item[i+1];
        }
    }
    ptree->size--;
    return true;
}

void Traverse (const Tree * ptree, void (* pfun)(Trnode trnode))
{

    if (ptree != NULL)
        InOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}


/* local functions */
static void InOrder(const Trnode * root, void (* pfun)(Trnode trnode))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(*root);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Trnode * root)
{
    Trnode * pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode (Trnode * new_node, Trnode * root)//排除重复情况
{
    if (ToLeft(&new_node->item[0], &root->item[0]))
    {
        if (root->left == NULL)      /* empty subtree       */
            root->left = new_node;   /* so add node here    */
        else
            AddNode(new_node, root->left);/* else process subtree*/
    }
    else
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
}

static bool ToLeft(const Item * i1, const Item * i2)
{
    if ((strcmp(i1->petname, i2->petname)) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
    if ((strcmp(i1->petname, i2->petname)) > 0)
        return true;
    else
        return false;
}

static Trnode * MakeNode(const Item * pi)
{
    Trnode * new_node;

    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->index=1;
        new_node->item[0] = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

static void DeleteNode(Trnode **ptr)
/* ptr is address of parent member pointing to target node  */
{
    Trnode * temp;
    if ( (*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ( (*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else    /* deleted node has two children */
    {
        /* find where to reattach right subtree */
        for (temp = (*ptr)->left; temp->right != NULL;
             temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr =(*ptr)->left;
        free(temp);
    }
}
