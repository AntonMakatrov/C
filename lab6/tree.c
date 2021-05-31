#include "tree.h"

void AddNode(int data, Item **node)
{
    if (*node == NULL) 
    {
        *node = (Item *)calloc(1, sizeof(Item));
        (*node)->data = data;
        (*node)->left = (*node)->right = NULL;
    } 
    else 
    {
        if (data < (*node)->data)
        AddNode(data, &(*node)->left); 
        else if (data > (*node)->data)
        AddNode(data, &(*node)->right);
        else
        puts("There is such element in the tree");
    }
}

int get(Item * node,int n,int c)
{
    
    if(n == c)  return 1;
    return ((node->left)?get(node->left,n,c+1):0) + ((node->right)?get(node->right,n,c+1):0);
}

void lvl(Item * root)
{
    int t = 0, l = 0;
    while((l = get(root, t++, 0)) != 0)
    {
        printf("lvl(%d) = %d\n", t, l);
    }
}