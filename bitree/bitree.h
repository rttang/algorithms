#ifndef BITREE_H
#define BITREE_H
#include <stdlib.h>

typedef struct BiTreeNode_
{
    void *data;
    struct BiTreeNode_ *left;
    struct BiTreeNode_ *right;
}BiTreeNode;
typedef struct BiTree_
{
    int size;
    int (*compare)(const void *key1,const void *key2);//大于返回1，小于返回-1,等于返回0
    void (*destroy)(void *data);
    BiTreeNode *root;
}BiTree;

void bitree_init(BiTree *tree,void (*destroy)(void *data));
void bitree_destroy(BiTree *tree);
int bitree_ins_left(BiTree *tree,BiTreeNode *node,const void *data);
int bitree_ins_right(BiTree *tree,BiTreeNode *node,const void *data);
void bitree_rem_left(BiTree *tree,BiTreeNode *node);
void bitree_rem_right(BiTree *tree,BiTreeNode *node);
int bitree_merge(BiTree *merge,BiTree *left,BiTree *right,const void *data);
BiTreeNode *bitree_search_inside(const void *data,BiTreeNode *node,BiTree *tree);
int bitree_search(BiTree *tree,const void *data,BiTreeNode **backNode);
int compare(int *data1,int *data2);

#define bitree_size(tree) ((tree)->size)
#define bitree_root(tree) ((tree)->root)
#define bitree_is_eob(tree) ((node) == NULL)
#define bitree_is_leaf(node) ((node)->left == NULL && (node)->reght == NULL)
#define bitree_data(node) ((node)->data)
#define bitree_left(node) ((node)->left)
#define bitree_right(node) ((node)->right)
#endif
