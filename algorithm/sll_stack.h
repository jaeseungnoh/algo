#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

typedef struct stacknode
{
    elementtype data;
    struct stacknode* nextnode;
} stacknode;

typedef struct stack_str
{
    struct stacknode* list_stack;
    struct stacknode* top;
} stack_str;

#endif