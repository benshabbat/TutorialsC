#include <stdio.h>

void merge(int *arr, int length);
void merge_sort_recursion(int *arr, int left, int right);
void merge_sorted_array(int *arr, int left, int middle, int right);

int main()
{

    int arr[] = {4, 5, 2, 3, 1, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]);
    merge(arr, length);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
void merge(int *arr, int length)
{
    merge_sort_recursion(arr, 0, length - 1);
}
void merge_sort_recursion(int *arr, int left, int right)
{
    int m = (right - left) / 2;
    if (left < right)
    {

        merge_sort_recursion(arr, left, m);
        merge_sort_recursion(arr, m + 1, right);
        merge_sorted_array(arr, left, m, right);
    }
}
void merge_sorted_array(int *arr, int left, int middle, int right)
{
    int left_length = middle - left + 1;
    int right_length = right - middle;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (i = 0; i < left_length; i++)
        temp_left[i] = arr[left + i];
    for (j = 0; j < right_length; j++)
        temp_right[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < left_length && j < right_length)
    {
        if (temp_left[i] <= temp_right[j])
        {
            arr[k] = temp_left[i];
            i++;
        }
        else
        {
            arr[k] = temp_right[j];
            j++;
        }
        k++;
    }

    while (i < left_length)
    {
        arr[k] = temp_left[i];
        i++;
        k++;
    }

    while (j < right_length)
    {
        arr[k] = temp_right[j];
        j++;
        k++;
    }
}
