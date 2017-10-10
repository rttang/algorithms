#include <stdlib.h>
#include <string>
#include "bitree.h"
void bitree_init(BiTree *tree,void (*destroy)(void *data))
{
    tree->size=0;
    tree->destroy=destroy;
    tree->root = NULL;

    return;
}
void bitree_destroy(Bitree *tree)
{
    bitree_rem_left(tree,NULL);
    memset(tree,0,sizeof(BiTree));
    return;
}
int bitree_ins_left(BiTree *tree,BiTreeNode *node,const void *data)
{
    BiTreeNode new_node,**position;

    if(node == NULL)
    {
        if(bitree_size(tree)>0)
            return -1;
        position = &tree->root;
    }
    else
    {
        if(bitree_left(node)!=NULL)
        return -1;

        position = &node->left;
    }
    if((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode)))==NULL)
        return -1;
    new_node->data = (void *)data;
    new_node->left = NULL;
    new_node->right  = NULL;
    *position = new_node;

    tree->size++;
    return 0;
}
int bitree_ins_right(BiTree *tree,BiTreeNode *node,const void *data)
{
    BiTreeNode new_node,**position;

    if(node == NULL)
    {
        if(bitree_size(tree)>0)
            return -1;
        position = &tree->root;
    }
    else
    {
        if(bitree_right(node)!=NULL)
        return -1;

        position = &node->right;
    }
    if((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode)))==NULL)
        return -1;
    new_node->data = (void *)data;
    new_node->left = NULL;
    new_node->right  = NULL;
    *position = new_node;

    tree->size++;
    return 0;
}
void bitree_rem_left(BiTree *tree,BiTreeNode *node)
{
    BiTreeNode **position;
    if(bitree_size(tree)==0)
        return ;
    if(node==NULL)
}
void bitree_rem_right(BiTree *tree,BiTreeNode *node);
int bitree_merge(BiTree *merge,BiTree *left,BiTree *right,const void *data);
