#include <stdio.h>

void merge_sort(int *arr, int start, int end);
void megrge_sorted_arr(int *arr, int start, int mid, int end);

int main()
{

    int arr[] = {55, -2, 44, 32, 12, 748, 45, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, size);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void merge_sort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);

        megrge_sorted_arr(arr, start, mid, end);
    }
}

void megrge_sorted_arr(int *arr, int start, int mid, int end)
{
    int temp[end - start + 1];

    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    for (i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}