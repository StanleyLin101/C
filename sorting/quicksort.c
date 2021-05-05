#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "quicksort.h"
int main()
{
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    gettimeofday(&start,NULL);

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

    quickSort(a, 0, 1000000-1);

    printf("sorted array : \n");
    for(int i = 0; i < 1000000; i++)
    {
        printf("%d\n", a[i]);
    }


    gettimeofday(&end,NULL);

    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    float sec;
    sec=(float)diff/1000000;
    printf("\nThe time required to sort 1,000,000 data is %f sec\n",sec);
    return 0;
}
