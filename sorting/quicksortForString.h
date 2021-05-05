#ifndef QSORTFORSTRING_H
#define QSORTFORSTRING_H
int partition(char **input, int, int);
void quickSort(char **input, int, int);
void swap(char *str1, char *str2);
void swap(char *str1, char *str2)
{
  char temp[1000000];
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
}
int partition(char **input, int left, int right)
{
    int i = left - 1;
    int j;
    for(j = left; j < right; j++)
    {
        if(strcmp(input[j] ,input[right])<=0)
        {
            i++;
            swap(input[i], input[j]);
        }
    }

    swap(input[i+1], input[right]);
    return i+1;
}

void quickSort(char **input, int left, int right)
{
    if(left < right)
    {
        int q = partition(input, left, right);
        quickSort(input, left, q-1);
        quickSort(input, q+1, right);
    }
}


#endif
