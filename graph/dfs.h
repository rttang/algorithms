#ifndef DFS_H
#define DFS_H
#include "graph.h"
#include "list.h"

typedef struct DfsVertex_
{
    void *data;
    VertexColor color;
}DfsVertex;
int dfs(Graph *graph,List *ordered);
int dfs_match_int(DfsVertex *key1,DfsVertex *key2);
void dfs_int(DfsVertex *dfsVertex,void *data);
#endif // DFS_H
