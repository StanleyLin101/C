#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdlib.h>
#define HashTableSize 11
struct hnode
{
    int value;
    struct hnode *next;
};
void insert_new_node(struct hnode **head, int data)
{
    struct hnode* new_node = malloc(sizeof(struct hnode));
    new_node->value = data;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct hnode *current = *head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}
int get_location(int data)
{
    return data % HashTableSize;
}
void insert_into_table(struct hnode **hashtable, int data)
{
    int location = get_location(data);
    if(hashtable[location] == NULL)
    {
        hashtable[location] = malloc(sizeof(struct hnode));
        struct hnode *head = NULL;
        insert_new_node(&head, data);
        hashtable[location] = head;
    }
    else
    {
        struct hnode *head = hashtable[location];
        insert_new_node(&head, data);
        hashtable[location] = head;
    }
}
int hash_search(struct hnode **hashtable, int target)
{
    int target_idx = get_location(target);
    struct hnode *head = hashtable[target_idx];
    if(head == NULL)
        return -1;
    struct hnode *current = head;
    int target_sub_idx = 0;
    while(current != NULL)
    {
        //printf("%d ",current->value);
        if(current->value == target)
            return target_sub_idx;
        target_sub_idx++;
        current = current->next;
    }
    return -1;
}
void display(struct hnode **hashtable)
{
    for(int i = 0; i<HashTableSize ; i++)
    {
        struct hnode *head = hashtable[i];
        printf("%d: ", i);
        if(head == NULL)
        {
            printf("NULL");
        }
        else
        {
            struct hnode *current = head;
            while(current != NULL)
            {
                printf("%d ",current->value);
                current = current->next;
            }
        }
        printf("\n");
    }
}
struct hnode **get_hashtable()
{
    struct hnode **hashtable = calloc(HashTableSize,sizeof(struct hnode*));
    return hashtable;
}


#endif
