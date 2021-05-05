#ifndef MERGESORT_H
#define MERGESORT_H
int a[10000000];
int aux[10000000];
void merge_sort(int i, int j, int a[],int aux[]);
void merge_sort(int i, int j, int a[],int aux[])
{
    if (j <= i)
    {
        return;
    }
    int mid = (i + j) / 2;
    merge_sort(i, mid, a,aux);
    merge_sort(mid + 1, j, a,aux);
    int left = i;
    int right = mid + 1;
    int k;
    for (k = i; k <= j; k++)
    {
        if (left == mid + 1)
        {
            aux[k] = a[right];
            right++;
        }
        else if (right == j + 1)
        {
            aux[k] = a[left];
            left++;
        }
        else if (a[left] < a[right])
        {
            aux[k] = a[left];
            left++;
        }
        else
        {
            aux[k] = a[right];
            right++;
        }
    }

    for (k = i; k <= j; k++)
    {
        a[k] = aux[k];
    }
}



#endif
