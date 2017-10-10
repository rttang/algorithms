#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "list.h"
#include "dfs.h"
//#include "bfs.h"
int main()
{

   /* Graph graphTest;
    BfsVertex bfsA[6];
    List listT;
    int num[6]={1,2,3,4,5,6},i;
    graph_init(&graphTest,(void *)match_int,NULL);
    for(i=0;i<6;i++)
    {
       bfs_int(&bfsA[i],&num[i]);
       graph_ins_vertex(&graphTest,(void *)&bfsA[i]);
    }
    graph_ins_edge(&graphTest,(void *)&bfsA[0],(void *)&bfsA[1]);
    graph_ins_edge(&graphTest,(void *)&bfsA[0],(void *)&bfsA[2]);
    graph_ins_edge(&graphTest,(void *)&bfsA[1],(void *)&bfsA[2]);
    graph_ins_edge(&graphTest,(void *)&bfsA[1],(void *)&bfsA[3]);
    graph_ins_edge(&graphTest,(void *)&bfsA[1],(void *)&bfsA[0]);
    graph_ins_edge(&graphTest,(void *)&bfsA[2],(void *)&bfsA[0]);
    graph_ins_edge(&graphTest,(void *)&bfsA[2],(void *)&bfsA[1]);
    graph_ins_edge(&graphTest,(void *)&bfsA[2],(void *)&bfsA[4]);
    graph_ins_edge(&graphTest,(void *)&bfsA[3],(void *)&bfsA[1]);
    graph_ins_edge(&graphTest,(void *)&bfsA[3],(void *)&bfsA[4]);
    graph_ins_edge(&graphTest,(void *)&bfsA[4],(void *)&bfsA[3]);
    graph_ins_edge(&graphTest,(void *)&bfsA[4],(void *)&bfsA[2]);
    graph_ins_edge(&graphTest,(void *)&bfsA[4],(void *)&bfsA[5]);
    graph_ins_edge(&graphTest,(void *)&bfsA[5],(void *)&bfsA[4]);
    bfs(&graphTest,&bfsA[0],&listT);
        printf("%d \n",*(int *)((BfsVertex *)listT.tail->data)->data);
        printf("%d \n",((BfsVertex *)listT.head->data)->hops);

        printf("%d \n",listT.size);
    */
    Graph graphTest;
    DfsVertex dfsA[7];
    List listT;
    ListElmt *elm;
    int num[7]={100,200,300,10,20,30,150},i;
    graph_init(&graphTest,(void *)dfs_match_int,NULL);
    for(i=0;i<7;i++)
    {
       dfs_int(&dfsA[i],&num[i]);
       graph_ins_vertex(&graphTest,(void *)&dfsA[i]);
    }
    graph_ins_edge(&graphTest,(void *)&dfsA[0],(void *)&dfsA[1]);
    graph_ins_edge(&graphTest,(void *)&dfsA[1],(void *)&dfsA[2]);
    graph_ins_edge(&graphTest,(void *)&dfsA[2],(void *)&dfsA[5]);
    graph_ins_edge(&graphTest,(void *)&dfsA[3],(void *)&dfsA[2]);
    graph_ins_edge(&graphTest,(void *)&dfsA[3],(void *)&dfsA[4]);
    graph_ins_edge(&graphTest,(void *)&dfsA[4],(void *)&dfsA[5]);
    dfs(&graphTest,&listT);
     printf("%d \n",listT.size);
    for(elm = list_head(&listT);elm != NULL;elm=list_next(elm))
    {
        printf("%d \n",*(int*)((DfsVertex *)elm->data)->data);
    }
    return 0;
}
