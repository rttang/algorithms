#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "set.h"
int main()
{
    int match(int *key1,int *key2)
    {
        if(*key1 == *key2) return 1;
        return 0;
    }
    Set setTest1,setTest2,setTest3;
    ListElmt *set1;
   // setTest1->match = match;
    int a[]={1,2,3,4,5,6,7,8,9,10},i=0,b[]={10,90,68,73,6,51,4,3,2,1},*data;
    set_init(&setTest1,(void *)match,NULL);
    set_init(&setTest2,(void *)match,NULL);
    set_init(&setTest3,(void *)match,NULL);
    for(i=0;i<10;i++)
    {
        set_insert(&setTest1,&a[i]);
        set_insert(&setTest2,&b[i]);
    }
    set_intersection(&setTest3,&setTest1,&setTest2);

    printf("%d\n",setTest3.size);
    set1=setTest3.head;
    for(i=0;i<setTest3.size;i++)
    {
        data=set1->data;
        printf("%d\n",(int)*data);
        set1=set1->next;
    }
    return 0;
}
