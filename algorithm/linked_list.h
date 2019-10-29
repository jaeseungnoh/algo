#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

typedef struct tagnode
{
    elementtype data;
    struct tagnode* nextnode;
} node;

node* sll_createnode(elementtype newdata);
void sll_destroynode(node* remove);
void sll_appendnode(node** head, node* newnode);
void sll_insertafter(node* current, node* newnode);
void sll_insertnewhead(node** head, node* newnode);
void sll_removenode(node** head, node* removenode);
node* sll_getnodeat(node** head, int location);
int sll_getnodecnt(node** head);

#endif