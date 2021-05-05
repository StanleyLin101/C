#ifndef MERGESORTFORSTRING_H
#define MERGESORTFORSTRING_H
void merge_sort(int i, int j, char **input,char **aux);
void merge_sort(int i, int j, char **input,char **aux)
{

    if (j <= i)
    {
        return;
    }
    int mid = (i + j) / 2;
    merge_sort(i, mid, input,aux);
    merge_sort(mid + 1, j, input,aux);
    int left = i;
    int right = mid + 1;
    int k;
    for (k = i; k <= j; k++)
    {
        if (left == mid + 1)
        {
            strcpy(aux[k],input[right]);
            right++;
        }
        else if (right == j + 1)
        {
            strcpy(aux[k] ,input[left]);
            left++;
        }
        else if (strcmp(input[left],input[right])<0)
        {
            strcpy(aux[k], input[left]);
            left++;
        }
        else
        {
            strcpy(aux[k] ,input[right]);
            right++;
        }
    }

    for (k = i; k <= j; k++)
    {
        strcpy(input[k],aux[k]);
    }
}



#endif

