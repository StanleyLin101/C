//Comparison the efficiency of data structure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "create_data.h"
#include "linked_list.h"
#include "array.h"
#include "query.h"
#include "hash.h"
int a[10000000];
int sorted_a[10000000];
int main(int argc,char *argv[])
{
    int arg_cnt = argc;
    //printf("%d\n",argc);
    int i_data_cnt , q_data_cnt;
    if(strcmp(argv[2],"1e4")==0) i_data_cnt = 10000;
    if(strcmp(argv[2],"1e5")==0) i_data_cnt = 100000;
    if(strcmp(argv[2],"1e6")==0) i_data_cnt = 1000000;
    if(strcmp(argv[4],"1e4")==0) q_data_cnt = 10000;
    if(strcmp(argv[4],"1e5")==0) q_data_cnt = 100000;
    if(strcmp(argv[4],"1e6")==0) q_data_cnt = 1000000;
    printf("number of insert data : %d\n",i_data_cnt);
    printf("number of query data : %d\n",q_data_cnt);
    printf("\n");
    int opt[10];
    int opt_idx = 0;
    for(int arg_idx = 4 ; arg_idx < arg_cnt ; arg_idx++)
    {
      if(strcmp(argv[arg_idx],"-bst")==0) opt[opt_idx] = 1;
      if(strcmp(argv[arg_idx],"-bs")==0) opt[opt_idx] = 2;
      if(strcmp(argv[arg_idx],"-arr")==0) opt[opt_idx] = 3;
      if(strcmp(argv[arg_idx],"-ll")==0) opt[opt_idx] = 4;
      if(strcmp(argv[arg_idx],"-hash")==0) opt[opt_idx] = 5;
      opt_idx++;
    }
  int reg = opt_idx;
  while(opt_idx)
  {
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;
    float sec;
    
    if(opt[opt_idx - reg] == 3)
    {//<array>
    printf("arr:\n");
    gettimeofday(&start,NULL);
   
    Insert_data(a,sorted_a,i_data_cnt);
    
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    sec=(float)diff/1000000;
    printf("building time : %.4f sec\n",sec);

    gettimeofday(&start,NULL);

    query(3, i_data_cnt , q_data_cnt);
    
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    sec=(float)diff/1000000;
    printf("query  time : %.4f sec\n",sec);
    if(opt_idx != 1)
    printf("--------------------------\n");
    //</array>
    }
    if(opt[opt_idx - reg] == 2)
    {
    //<array binary search>
    printf("bs:\n");
    gettimeofday(&start,NULL);
      
    Insert_data(a,sorted_a,i_data_cnt);
      
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    sec=(float)diff/1000000;
    printf("building time : %.4f sec\n",sec);

    gettimeofday(&start,NULL);
    
    query(2, i_data_cnt , q_data_cnt);
    
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    sec=(float)diff/1000000;
    printf("query time : %.4f sec\n",sec);
    if(opt_idx != 1)
    printf("--------------------------\n");
    //</array binary search>
    }
    if(opt[opt_idx - reg] == 4)
    {
    //<ll>
    printf("linked list:\n");
    gettimeofday(&start,NULL);

    struct lnode* L;
    L = ll_create_data(L,i_data_cnt,a);
    //traverse_print(L,i_data_cnt);

    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    sec=(float)diff/1000000;
    printf("building time : %.4f sec\n",sec);
    
    gettimeofday(&start,NULL);
    
    query(4, i_data_cnt , q_data_cnt);
    
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    sec=(float)diff/1000000;
    printf("query time : %.4f sec\n",sec);
    if(opt_idx != 1)
    printf("--------------------------\n");
    //</ll>
    }
    if(opt[opt_idx - reg] == 1)
    {
    //<bst>
    printf("bst:\n");
    gettimeofday(&start,NULL);
    
    struct bnode *B;
    B = bst_create_data(B,i_data_cnt,a);
    //inorder(B);

    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    sec=(float)diff/1000000;
    printf("building time : %.4f sec\n",sec);
      
    gettimeofday(&start,NULL);
    
    query(1, i_data_cnt , q_data_cnt);
    
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    sec=(float)diff/1000000;
    printf("query time : %.4f sec\n",sec);
    if(opt_idx != 1)
    printf("--------------------------\n");
    //</bst>
    }

    if(opt[opt_idx - reg] == 5)
    {
    //<hash>
    printf("hash:\n");
    gettimeofday(&start,NULL);

    //struct hnode **table = get_hashtable();
    table = hash_create_data(table , i_data_cnt ,a);
    //display(table);
    
    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    sec=(float)diff/1000000;
    printf("building time : %.4f sec\n",sec);
 
    gettimeofday(&start,NULL);
    
    query(5, i_data_cnt , q_data_cnt);

    gettimeofday(&end,NULL);
    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;  
    sec=(float)diff/1000000;
    printf("query time : %.4f sec\n",sec);
    if(opt_idx != 1)
    printf("--------------------------\n");
    //</hash>
    }
    reg = reg - 2;
    opt_idx--;
  }
    return 0;
}

