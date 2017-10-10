#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main()
{
   /* Stack stackTest;
    int i,a[3];
    stack_init(&stackTest,NULL);
    printf("输入三项数据：\n");
    for(i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
        stack_push(&stackTest,&a[i]);
    }
     printf("输出三项数据：\n");
     for(i=0;i<3;i++)
    {
        int *data;
        stack_pop(&stackTest,(void **)&data);
        printf("%d \n",*data);
    }*/
    Queue queueTest;
    int i,a[3];
    queue_init(&queueTest,NULL);
    printf("输入三项数据：\n");
    for(i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
        queue_enqueue(&queueTest,&a[i]);
    }
     printf("输出三项数据：\n");
     for(i=0;i<3;i++)
    {
        int *data;
        queue_dequeue(&queueTest,(void **)&data);
        printf("%d \n",*data);
    }

    return 0;
}
