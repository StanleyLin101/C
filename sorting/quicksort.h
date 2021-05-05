#ifndef QUICKSORT_H
#define QUICKSORT_H
int a[1000000];
int partition(int[], int, int);
void quickSort(int[], int, int);
void swap(int*,int*);
void swap(int *p1,int *p2)
{
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}
int partition(int number[], int left, int right)
{
    int i = left - 1;
    int j;
    for(j = left; j < right; j++)
    {
        if(number[j] <= number[right])
        {
            i++;
            swap(&number[i], &number[j]);
        }
    }

    swap(&number[i+1], &number[right]);
    return i+1;
}

void quickSort(int number[], int left, int right)
{
    if(left < right)
    {
        int q = partition(number, left, right);
        quickSort(number, left, q-1);
        quickSort(number, q+1, right);
    }
}
#endif
