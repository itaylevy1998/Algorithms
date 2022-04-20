#pragma once
#include "quickSort.h"

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(vector<int>& arr, int left, int right)
{
    int x = arr[right];
    int i = left - 1;
    int j = left;

    while (j <= right - 1)
    {
        if (arr[j] <= x)
        {
            i += 1;
            swap(&arr[i], &arr[j]);
        }
        j += 1;
    }

    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quickSort(vector<int>& arr, int left, int right)
{
    int pivot;

    if (left < right)
    {
        pivot = partition(arr, left, right);
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
}
