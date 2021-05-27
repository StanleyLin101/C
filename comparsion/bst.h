#ifndef BST_H
#define BST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct bnode
{
    int data;
    struct bnode *right_child;
    struct bnode *left_child;
};
struct bnode* bst_new_node(int input)
{
    struct bnode *p;
    p = (struct bnode*)malloc(sizeof(struct bnode));
    //p = malloc(sizeof(struct node));
    p->data = input;
    p->left_child = NULL;
    p->right_child = NULL;
    return p;
}

struct bnode* insert(struct bnode *root, int input)
{
    if(root==NULL)
        return bst_new_node(input);
    else if(input > root->data)
        root->right_child = insert(root->right_child, input);
    else
        root->left_child = insert(root->left_child,input);
    return root;
}

struct bnode* bst_search(struct bnode *root , int target)
{
    struct bnode *q;
    while(root!=NULL)
    {
        q = root;
        if (root->data > target)
            root = root->left_child;
        else
            root = root->right_child;
    }
    return q;
}

void inorder(struct bnode *root)
{
    if(root!=NULL)
    {
        inorder(root->left_child); //Left child
        printf("%d\n", root->data); //root
        inorder(root->right_child); //Right child
    }
}

#endif
