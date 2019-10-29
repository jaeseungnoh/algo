#include "linked_list.h"
/*Single linked list*/

node* sll_createnode(elementtype newdata)
{
    node* newnode = (node*)malloc(sizeof(node));

    newnode->data = newdata;
    newnode->nextnode = NULL;

    return newnode;
}

void sll_destroynode(node* remove)
{
    if(remove == NULL)
        printf("already destroyed!!");
    
    free(remove);
}

void sll_appendnode(node** head, node* newnode)
{
    if(*head == NULL)
        *head = newnode;
    else
    {
        node* tail = *head;
        while(tail->nextnode != NULL)
            tail = tail->nextnode;
        tail->nextnode = newnode;
    }
    //printf("%s : head : 0x%x \n",__func__, *head);
}

void sll_insertafter(node* current, node* newnode)
{
    newnode->nextnode = current->nextnode;
    current->nextnode = newnode;
}

void sll_insertnewhead(node** head, node* newnode)
{
    if(*head == NULL)
        *head = newnode;

    else
    {
        newnode->nextnode = *head;
        *head = newnode;
    }
}

void sll_removenode(node** head, node* removenode)
{
    if(*head == removenode)
    {
        *head = removenode->nextnode;
    }
    else
    {
        node* tmp = *head;
        while((tmp != NULL) && (tmp->nextnode != removenode))
            tmp=tmp->nextnode;
        
        if (tmp != NULL)
            tmp->nextnode = removenode->nextnode;
    }
}

node* sll_getnodeat(node** head, int location)
{
    node* current = *head;
    while(current != NULL && (--location) >= 0)
        current = current->nextnode;
    
    return current;
}

int sll_getnodecnt(node** head)
{
    int cnt = 0;
    node* tmp = *head;
       
    while(tmp != NULL)
    {
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
        newnode = sll_createnode((elementtype)i);
        sll_appendnode(&list, newnode);
    }

    printf("node count : %d \n", sll_getnodecnt(&list));
    for(i = 0; i<5; i++)
    {
        current = sll_getnodeat(&list, 0);
        printf("data : %d\n", current->data);
        sll_removenode(&list, current);
        sll_destroynode(current);
        printf("node count2 : %d\n", sll_getnodecnt(&list));
    }
    return 0;
}