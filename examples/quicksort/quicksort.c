#include <stdio.h>

void swap(int *x, int *y);
void quick_sort(int *arr, int length);
void quick_sort_recurion(int *arr, int low, int high);
int partition(int *arr, int low, int high);

int main()
{
    int arr[] = {4, 5, 2, 3, 1, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void swap(int *x, int *y)
{
    int temp =*x;
    *x = *y;
    *y = temp;
}

void quick_sort(int *arr, int length)
{
    quick_sort_recurion(arr, 0, length - 1);
}

void quick_sort_recurion(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);
        quick_sort_recurion(arr, low, pivot_index - 1);
        quick_sort_recurion(arr, pivot_index + 1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot_value = arr[high];
    int i=low;
    for (int j = low; j< high; j++)
    {
        if (arr[j] <= pivot_value)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[high]);
    return i;
}