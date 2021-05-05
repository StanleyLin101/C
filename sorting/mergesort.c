#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "mergesort.h"

int main()
{
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    gettimeofday(&start,NULL);

    int n, i, d, swap;
    FILE *fp;
    int number;
    fp = fopen("dataset1.txt", "r");
    if (fp == NULL)
    {
        printf("Can't open file.\n");
    }
    else
    {
        for(int i=0; i<1000000; i++)
        {
            fscanf(fp, "%d", &number);
            a[i] = number;
        }
        fclose(fp);
    }

    merge_sort(0, 1000000 - 1, a,aux);

    printf("sorted array : \n");

    for (i = 0; i < 1000000; i++)
        printf("%d\n", aux[i]);

    gettimeofday(&end,NULL);

    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    float sec;
    sec=(float)diff/1000000;
    printf("\nThe time required to sort 1,000,000 data is %f sec\n",sec);
    return 0;
}
