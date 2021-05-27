#ifndef CREATEDATA_H
#define CREATEDATA_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "linked_list.h"
#include "bst.h"
#include "hash.h"
int a[10000000];
int sorted_a[10000000];
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Insert_data(int a[],int sorted_a[],int num)
{
    srand( (unsigned)time( NULL ) );
    for(int i=0; i<num; i++)
    {
        a[i] = i;
        sorted_a[i] = i;
        //printf("%d\n",a[i]);
    }
    for (int i = num - 1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);

        // Swap arr[i] with the element at random index
        swap(&a[i], &a[j]);
    }
    //printf("Data generated successfully\n");
}
struct lnode *L;
struct lnode* ll_create_data(struct lnode *L, int InsertCnt,int a[])
{
  L = new_node(a[0]);
  for(int i = 1 ; i<InsertCnt ; i++)
  L = Insert_tail(L,a[i]);
  return L;
}
struct bnode *B;
struct bnode* bst_create_data(struct bnode *B, int InsertCnt,int a[])
{
  B = bst_new_node(a[0]);
  for(int i = 1 ; i<InsertCnt ; i++)
  B = insert(B,a[i]);
  return B;
}
struct hnode **table;
struct hnode **hash_create_data(struct hnode **table, int InsertCnt,int a[])
{
  table = get_hashtable();
  for(int i = 0 ; i<InsertCnt ; i++)
  insert_into_table(table,a[i]);
  return table;
}

#endif

