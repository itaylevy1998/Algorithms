#pragma once
#include "quickSort.h"

void swap(Edge* x, Edge* y)
{
    Edge temp = *x;
    *x = *y;
    *y = temp;
}

int partition(vector<Edge>& arr, int left, int right)
{
    Edge x = arr[right];
    int i = left - 1;
    int j = left;

    while (j <= right - 1)
    {
        if (arr[j].getWeight() <= x.getWeight())
        {
            i += 1;
            swap(&arr[i], &arr[j]);
        }
        j += 1;
    }

    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quickSort(vector<Edge>& arr, int left, int right)
{
    int pivot;

    if (left < right)
    {
        pivot = partition(arr, left, right);
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
}
