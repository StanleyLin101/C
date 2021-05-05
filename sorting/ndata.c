#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
int a[10000000];
int main()
{
    FILE *fp;
    fp=fopen("dataset1.txt","w");
    if(fp==NULL)
    {
        printf("cannot open file/n");
        exit(1);
    }
    srand( (unsigned)time( NULL ) );
    for(int i=0; i<1000000; i++)
    {
        a[i]=rand();
        fprintf(fp,"%d\n",a[i]);
    }
    printf("Data generated successfully\n");
    return 0;
}
