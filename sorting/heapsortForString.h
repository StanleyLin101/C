#ifndef HEAPSORTFORSTRING_H
#define HEAPSORTFORSTRING_H
void swap(char *str1, char *str2);
void heapify(char **input, int n, int i);
void heapSort(char **input, int n);
void swap(char *str1, char *str2)
{
  char temp[1000000];
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
}
void heapify(char **input, int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && strcmp(input[left] ,input[largest])>0)
        largest = left;

    if (right < n && strcmp(input[right] ,input[largest])>0)
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(input[i], input[largest]);
        heapify(input, n, largest);
    }
}
void heapSort(char **input, int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(input, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(input[0], input[i]);

        // Heapify root element to get highest element at root again
        heapify(input, i, 0);
    }
}

#endif
