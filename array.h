#ifndef ARRAY_H
#define ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int array_search(int a[], int target , int numCnt)
{
  for(int i = 0; i < numCnt ; i++)
  {
    if(a[i] == target)
    {
      return i;
    }
  }
  return -1;
}

int binarysearch(int data[], int target, int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (data[mid] == target)
        {
            return mid;
        }
        else if (data[mid] > target)
        {
            high = mid - 1;
        }
        else if (data[mid] < target)
        {
            low = mid + 1;
        }
    }
    return -1;
}

#endif
