#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include "heapsortForString.h"
int main()
{
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    gettimeofday(&start,NULL);

    char **a;
    a = malloc(1000000 * sizeof(char*));
    for (int i = 0; i < 1000000; i++)
        a[i] = malloc((100+1) * sizeof(char));
    FILE *fp;
    char input[1000];
    fp = fopen("dataset2.txt", "r");
    if (fp == NULL)
    {
        printf("Can't open file.\n");
    }
    else
    {
        int idx = 0;
        while (fgets(input, sizeof(input), fp))
        {
            strcpy(a[idx],input);
            idx++;
        }
        fclose(fp);
    }
    heapSort(a, 1000000);
    printf("sorted string : \n");
    for(int i = 0; i < 1000000; i++)
    {
        printf("%s", a[i]);
    }
    free(a);

    gettimeofday(&end,NULL);

    diff = 1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
    float sec;
    sec=(float)diff/1000000;
    printf("\nThe time required to sort 1,000,000 data is %f sec\n",sec);
    return 0;
}

