#include <stdio.h>
#include "dfs.h"
#include "graph.h"
#include "list.h"
/**
**graph:需要处理的图
**adjlist:起始顶点
**ordered:完成拓扑排序后返回的顶点链表
**/
static int dfs_main(Graph *graph,AdjList *adjlist,List *ordered)
{
    AdjList *clr_adjlist;//遍历的顶点返回的邻接链表
    DfsVertex *clr_vertex,*adj_vertex;
    ListElmt *member;

    ((DfsVertex *)adjlist->vertex)->color = gray;//起始顶点涂灰

    for(member = list_head(&adjlist->adjacent);member != NULL;member = list_next(member)) //遍历顶点的邻接链表
    {
        adj_vertex = list_data(member);
        if(graph_adjlist(graph,adj_vertex,&clr_adjlist)!=0)
            return -1;
        clr_vertex = clr_adjlist->vertex;
        if(clr_vertex->color == white)
        {
            if(dfs_main(graph,clr_adjlist,ordered) != 0)
                return -1;
        }
    }
    ((DfsVertex *)adjlist->vertex)->color = black;

    if(list_ins_next(ordered,NULL,(DfsVertex *)adjlist->vertex)!=0)
        return -1;
    return 0;
}

int dfs(Graph *graph,List *ordered)
{
    DfsVertex *vertex;
    ListElmt *element;

    for(element = list_head(&graph_adjlists(graph));element != NULL;element = list_next(element))//初始化全部涂白
    {
        vertex = ((AdjList *)list_data(element))->vertex;
        vertex->color = white;
    }

    list_init(ordered,NULL);

    for(element = list_head(&graph_adjlists(graph));element != NULL;element = list_next(element))
    {
        vertex = ((AdjList *)list_data(element))->vertex;

        if(vertex->color==white)
        {
            if(dfs_main(graph,(AdjList *)list_data(element),ordered)!=0)
            {
                list_destroy(ordered);
                return -1;
            }
        }

    }
    return 0;
}
void dfs_int(DfsVertex *dfsVertex,void *data)
{
    DfsVertex dfs;
    *dfsVertex = dfs;
    dfsVertex->data = data;
    return;
}
int dfs_match_int(DfsVertex *key1,DfsVertex *key2)
{
        if(*(int *)(key1->data) == *(int *)(key2->data)) return 1;
        return 0;
}
