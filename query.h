#ifndef QUERY_H
#define QUERY_H
#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "bst.h"
#include "linked_list.h"
#include "create_data.h"
#include "hash.h"
// 接參數no 1是bst 2是bs 3是array 4是linked list 5是hash
void query(int no ,int i_data_cnt ,  int q_data_cnt)
{
  int target;
  for(int i = 0 ; i < q_data_cnt ; i++)
  {
    srand(i);
    target = rand()%i_data_cnt;
    //printf("target : %d\n",target);
    if(no == 1)//bst
    {
      struct bnode *bst_index = bst_search(B,target);
    }
    if(no == 2)//bs
    {
      int bs_index = binarysearch(sorted_a,target,i_data_cnt);
      //printf("serach array by binary search ,target index = %d\n",bs_index);
    }
    if(no == 3)//array
    {
      int a_index = array_search(a,target,i_data_cnt);
      //printf("serach array by sequential ,target index = %d\n",a_index);
    }
    if(no == 4)//ll
    {
      //struct lnode *L;
      struct lnode *ll_index = search(L,target);
      //printf("serach array by sequential ,target index = %s\n",ll_index);
    }
    if(no == 5)//hash
    {
      int hash_index = hash_search(table,target);
      //printf("%d\n",hash_index);
    }
  }
}

#endif

