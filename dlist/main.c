#include <stdio.h>
#include <string.h>

#include "dlist.h"

void dlist_init(DList *list,void (*destroy)(void *data))
{
    list->size = 0;
    list->destory = destory;
    list->head=NULL;
    list->tail=NULL;

    return;
}
void dlist_destroy(DList *list)
{
    void *data;

    while(dlist_size(list)>0)
    {
        if(dlist_remove(list,dlist_tail(list),(void **)&data)==0&&list->destory != NULL)
        {
            list->destory(data);
        }
    }
}
int dlist_ins_next(DList *list,DListElmt *element,const void *data)
{

}
int dlist_ins_prev(DList *list,DListElmt *element,const void *data);
int dlist_remove(DList *list,DListElmt *element,const void **data)
{
    if(element == NULL || dlist_size(list)==0)
    {
        return -1;
    }
    *data = element->data;
    if(element==list->head)
    {
        list->head = element->next;

        if(list->head == NULL)
            list->tail=NULL;
        else
            element->next->prev = NULL;
    }
    else
    {
        element->prev->next=element->next;
        if(element->next=NULL)
            list->tail=element->prev;
        else
            element->next->prev = element->prev;
    }
    free(element);

    list->size--;
    return 0;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
