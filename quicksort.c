#include <stdio.h>

void swap(int *x, int *y);
void quick_sort(int *arr, int length);
void quick_sort_recurion(int *arr, int low, int high);
void partition(int *arr, int low, int high);

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
    int temp = x;
    *x = *y;
    *y = temp;
}