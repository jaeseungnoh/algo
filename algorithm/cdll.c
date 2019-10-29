#include "cdll.h"
/*Single linked list*/

node* cdll_createnode(elementtype newdata)
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

void cdll_destroynode(node* remove)
{
    if(remove == NULL)
        printf("already destroyed!!");
    
    free(remove);
}

void cdll_appendnode(node** head, node* newnode)
{
    if(*head == NULL)
    {
        *head = newnode;
        (*head)->nextnode = *head;
        (*head)->prevnode = *head;
    }
    else
    {
        node* tail = (*head)->prevnode;
        newnode->prevnode = tail;
        newnode->nextnode = *head;
        tail->nextnode = newnode;
        (*head)->prevnode = newnode;
    }
    //printf("%s : head : 0x%x \n",__func__, *head);
}

void cdll_insertafter(node* current, node* newnode)
{
    newnode->nextnode = current->nextnode;
    newnode->prevnode = current->nextnode->prevnode;
    current->nextnode->prevnode = newnode;
    current->nextnode = newnode;
}

/*Check it one more time!!*/
void cdll_removenode(node** head, node* removenode)
{
    if(*head == removenode)
    {
        if((*head)->nextnode == *head && (*head)->prevnode == *head)
            *head = NULL;
        else
        {
            (*head)->prevnode->nextnode = (*head)->nextnode;
            (*head)->nextnode->prevnode = (*head)->prevnode;
            *head = removenode->nextnode;

            removenode->prevnode = NULL;
            removenode->nextnode = NULL;
        }
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

node* cdll_getnodeat(node** head, int location)
{
    node* current = *head;
    while(current != NULL && (--location) >= 0)
        current = current->nextnode;
    
    return current;
}

int cdll_getnodecnt(node** head)
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
        newnode = cdll_createnode((elementtype)i);
        cdll_appendnode(&list, newnode);
    }

    for(i = 0; i<5; i++)
    {
        current = cdll_getnodeat(&list, 0);
        cdll_removenode(&list, current);
        cdll_destroynode(current);
    }

 
    for(i = 0; i<5; i++)
    {
        newnode = cdll_createnode((elementtype)i);
        cdll_appendnode(&list, newnode);
    }

    printf("node count : %d \n", cdll_getnodecnt(&list));
#if 1
    for(i = 4; i >= 0; i--)
    {
#if 1
        current = cdll_getnodeat(&list, i);
        cdll_removenode(&list, current);
        cdll_destroynode(current);
#endif
    }
#endif


 
    for(i = 0; i<5; i++)
    {
        newnode = cdll_createnode((elementtype)i);
        cdll_appendnode(&list, newnode);
    }

    printf("node count : %d \n", cdll_getnodecnt(&list));
    for(i = 2; i >= 0; i--)
    {
        current = cdll_getnodeat(&list, 1);
        printf("data : %d\n", current->data);
        cdll_removenode(&list, current);
        cdll_destroynode(current);
        printf("node count2 : %d\n", cdll_getnodecnt(&list));
    }

    return 0;
}