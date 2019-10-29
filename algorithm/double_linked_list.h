#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

typedef struct tagnode
{
    elementtype data;
    struct tagnode* prevnode;
    struct tagnode* nextnode;
} node;

#endif