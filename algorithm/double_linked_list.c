#include "double_linked_list.h"
/*Single linked list*/

node* dll_createnode(elementtype newdata)
{
    node* newnode = (node*)malloc(sizeof(node));

    if (newnode != NULL)
    {
        newnode->data = newdata;
        newnode->prevnode = NULL;
        newnode->nextnode = NULL;
    }
    else
    {
        printf("%s : failed to alloc memory\n",__func__);
    }
    return newnode;
}

void dll_destroynode(node* remove)
{
    if(remove == NULL)
        printf("already destroyed!!");
    
    free(remove);
}

void dll_appendnode(node** head, node* newnode)
{
    if(*head == NULL)
        *head = newnode;
    else
    {
        node* tail = *head;
        while(tail->nextnode != NULL)
            tail = tail->nextnode;
        tail->nextnode = newnode;
        newnode->prevnode = tail;
    }
    //printf("%s : head : 0x%x \n",__func__, *head);
}

void dll_insertafter(node* current, node* newnode)
{
    newnode->nextnode = current->nextnode;
    newnode->prevnode = current->nextnode->prevnode;
    current->nextnode->prevnode = newnode;
    current->nextnode = newnode;
}

void dll_removenode(node** head, node* removenode)
{
    if(*head == removenode)
    {
        *head = removenode->nextnode;
        if(*head != NULL)
            (*head)->prevnode = NULL;
        removenode->prevnode = NULL;
        removenode->nextnode = NULL;
    }
    else
    {
        if(removenode->prevnode != NULL)
            removenode->prevnode->nextnode = removenode->nextnode;
        if(removenode->nextnode != NULL)
            removenode->nextnode->prevnode = removenode->prevnode;

        removenode->prevnode = NULL;
        removenode->nextnode = NULL;
    }
}

node* dll_getnodeat(node** head, int location)
{
    node* current = *head;
    while(current != NULL && (--location) >= 0)
        current = current->nextnode;
    
    return current;
}

int dll_getnodecnt(node** head)
{
    int cnt = 0;
    node* tmp = *head;
       
    while(tmp != NULL)
    {
        printf("%s : data = %d \n", __func__, tmp->data);
        tmp = tmp->nextnode;
        cnt++;
    }

    return cnt;
}

int main(void)
{
    int i = 0;
    int count = 0;
    node* list = NULL;
    node* newnode = NULL;
    node* current = NULL;

    for(i = 0; i<5; i++)
    {
        newnode = dll_createnode((elementtype)i);
        dll_appendnode(&list, newnode);
    }

    for(i = 0; i<5; i++)
    {
        current = dll_getnodeat(&list, 0);
        dll_removenode(&list, current);
        dll_destroynode(current);
    }

 
    for(i = 0; i<5; i++)
    {
        newnode = dll_createnode((elementtype)i);
        dll_appendnode(&list, newnode);
    }

    printf("node count : %d \n", dll_getnodecnt(&list));
#if 1
    for(i = 4; i >= 0; i--)
    {
#if 1
        current = dll_getnodeat(&list, i);
        dll_removenode(&list, current);
        dll_destroynode(current);
#endif
    }
#endif


 
    for(i = 0; i<5; i++)
    {
        newnode = dll_createnode((elementtype)i);
        dll_appendnode(&list, newnode);
    }

    printf("node count : %d \n", dll_getnodecnt(&list));
    for(i = 2; i >= 0; i--)
    {
        current = dll_getnodeat(&list, 1);
        printf("data : %d\n", current->data);
        dll_removenode(&list, current);
        dll_destroynode(current);
        printf("node count2 : %d\n", dll_getnodecnt(&list));
    }

    return 0;
}