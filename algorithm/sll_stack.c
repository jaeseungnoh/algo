#include "sll_stack.h"

stack_str* create_stack(void)
{
    stack_str* stackdata = (stack_str*)malloc(sizeof(stack_str));

    stackdata->list_stack = NULL;
    stackdata->top = NULL;

    return stackdata;
}

void destroy_stack(stack_str* stackdata)
{
    if(stackdata == NULL)
    {
        printf("%s : already destoryed \n",__func__);
        return;
    }
    else
        free(stackdata);
}

stacknode* create_node(elementtype data)
{
    stacknode* node = (stacknode*)malloc(sizeof(stacknode));
    node->data = data;
    node->nextnode = NULL;

    return node;
}

void destroy_node(stacknode* node)
{
    if(node == NULL)
    {
        printf("%s : already destoryed \n",__func__);
        return;
    }
    else
        free(node);
}

void push_stack(stack_str* stackdata, stacknode* node)
{
    if(stackdata == NULL)
    {
        printf("%s : stack invalid \n", __func__);
        return;
    }

    if(stackdata->list_stack == NULL)
    {
        stackdata->list_stack = node;
    }
    else
    {
        stackdata->top->nextnode = node;
    }
    stackdata->top = node;
}

stacknode* pop_stack(stack_str* stackdata)
{
    if(stackdata == NULL)
    {
        printf("%s : stack invalid \n", __func__);
        return NULL;
    }

    if(stackdata->list_stack == NULL)
    {
        printf("stack is empty, nothing to pop\n");
        return NULL;
    }

    stacknode* pop_node = stackdata->top;

    if(stackdata->list_stack == stackdata->top)
    {
        stackdata->list_stack = NULL;
        stackdata->top = NULL;
    }
    else
    {
        stacknode* temp = stackdata->list_stack;
        while(temp != NULL && temp->nextnode != stackdata->top)
            temp = temp->nextnode;
        temp->nextnode = NULL;
        stackdata->top = temp;
    }

    return pop_node;
}

int count_stack(stack_str* stackdata)
{
    if(stackdata == NULL)
    {
        printf("%s : stack invalid \n", __func__);
        return 0;
    }

    stacknode* temp = stackdata->list_stack;
    int cnt = 0;

    while(temp != NULL && cnt < 10)
    {
        temp = temp->nextnode;
        cnt++;
    }

    return cnt;
}

stacknode* top_stack(stack_str* stackdata)
{
    return stackdata->top;
}

int main(void)
{
    stack_str* stack_data = NULL;
    stacknode* node = NULL;
    int i = 0;

    stack_data = create_stack();

    for(i=0; i<1; i++)
    {
        node = create_node(i);
        push_stack(stack_data, node);
    }
    printf("stack count(1) : %d\n", count_stack(stack_data));

    for(i=0; i<1; i++)
    {
        node = pop_stack(stack_data);
        destroy_node(node);
    }
    printf("stack count(2) : %d\n", count_stack(stack_data));

    for(i=0; i<5; i++)
    {
        node = create_node(i);
        push_stack(stack_data, node);
    }
    printf("stack count(3) : %d\n", count_stack(stack_data));

    for(i=0; i<7; i++)
    {
        node = pop_stack(stack_data);
        destroy_node(node);
    }
    printf("stack count(4) : %d\n", count_stack(stack_data));
    destroy_stack(stack_data);

    return 0;
}