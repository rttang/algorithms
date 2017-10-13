#include <stdlib.h>
#include <string.h>
#include "bitree.h"
void bitree_init(BiTree *tree,void (*destroy)(void *data))
{
    tree->size=0;
    tree->destroy=destroy;
    tree->root = NULL;

    return;
}
void bitree_destroy(BiTree *tree)
{
    bitree_rem_left(tree,NULL);
    memset(tree,0,sizeof(BiTree));
    return;
}
int bitree_ins_left(BiTree *tree,BiTreeNode *node,const void *data)
{
    BiTreeNode *new_node,**position;

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
    BiTreeNode *new_node,**position;

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
        position = &tree->root;
    else
        position = &node->left;
    if(*position != NULL)
    {
        bitree_rem_left(tree,*position);
        bitree_rem_right(tree,*position);

        if(tree->destroy !=NULL)
        {
            tree->destroy((*position)->data);
        }
        free(*position);
        *position = NULL;
        tree->size--;
    }
    return ;
}
void bitree_rem_right(BiTree *tree,BiTreeNode *node)
{
     BiTreeNode **position;
    if(bitree_size(tree)==0)
        return ;
    if(node==NULL)
        position = &tree->root;
    else
        position = &node->right;
    if(*position != NULL)
    {
        bitree_rem_left(tree,*position);
        bitree_rem_right(tree,*position);

        if(tree->destroy !=NULL)
        {
            tree->destroy((*position)->data);
        }
        free(*position);
        *position = NULL;
        tree->size--;
    }
    return ;
}
int bitree_merge(BiTree *merge,BiTree *left,BiTree *right,const void *data)
{
    bitree_init(merge,left->destroy);

    if(bitree_ins_left(merge,NULL,data)!=0)
    {
        bitree_destroy(merge);
        return -1;
    }
    bitree_root(merge)->left = bitree_root(left);
    bitree_root(merge)->right = bitree_root(right);
    left->root=NULL;
    left->size=0;
    right->root=NULL;
    right->size=0;
    return 0 ;
}
int bitree_search(BiTree *tree,const void *data,BiTreeNode **backNode)
{
    BiTreeNode *node;
    if(bitree_size(tree)==0)
        return -1;
    node = bitree_root(tree);
    if(tree->compare(data,(int*)bitree_data(node))==0) return 1;
    if(tree->compare(data,(int*)bitree_data(node))==-1)
        *backNode = bitree_search_inside(data,bitree_left(node),tree);
    else *backNode = bitree_search_inside(data,bitree_right(node),tree);
    return 0;

}
BiTreeNode *bitree_search_inside(const void *data,BiTreeNode *node,BiTree *tree)
{
    if(node == NULL || tree->compare(data,(int*)bitree_data(node))==0) return node;
    if(tree->compare(data,(int*)bitree_data(node))==-1)
         bitree_search_inside(data,bitree_left(node),tree);
    else  bitree_search_inside(data,bitree_right(node),tree);
}
