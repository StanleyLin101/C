#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct lnode
{
    int key;
    struct lnode *next;
};
struct lnode* new_node(int input)
{
    struct lnode *p;
    p = (struct lnode*)malloc(sizeof(struct lnode));
    //p = (struct lnode*)malloc(10000000);
    //p = malloc(sizeof(struct lnode));
    p->key = input;
    p->next = NULL;
    return p;
}
struct lnode* search(struct lnode* head, int input)
{
    struct lnode* current = head;
    while (current != NULL)
    {
        if (current->key == input)
            return current;
        current = current->next;
    }
    return NULL;
}
struct lnode *Insert_tail(struct lnode *L, int key)
{
    struct lnode *p, *last, *orig_p;
    p = (struct lnode*)malloc(sizeof(struct lnode));
    p->key = key;
    orig_p = p;
    if(L == NULL)
    {
        p->next = NULL;
        return p;
    }
    p = L;
    while(p)
    {
        last = p;
        p = p->next;
    }
    last->next = orig_p;
    orig_p->next = NULL;
    return L;
}
void traverse_print(struct lnode *L, int InsertCnt)
{
    struct lnode *p = L;
    while(p)
    {
        if(InsertCnt>1)
        {
            printf("%d\n",p->key);
            p = p->next;
            InsertCnt--;
        }
        else
        {
            printf("%d",p->key);
            p = p->next;
        }

    }
}

#endif

