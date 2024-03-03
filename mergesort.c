#include <stdio.h>

void merge_sort(int *arr, int length);
void merge_sort_recursion(int *arr, int left, int right);
void merge_sorted_arrays(int *arr, int left, int mid, int right);

int main()
{
    int array[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = 10;

    merge_sort(array, length);

    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}

void merge_sort(int *arr, int length)
{

    merge_sort_recursion(arr, 0, length - 1);
}

void merge_sort_recursion(int *arr, int left, int right)
{

    if (left < right)
    {

        int mid = left + (right - left) / 2;

        merge_sort_recursion(arr, left, mid);
        merge_sort_recursion(arr, mid + 1, right);

        merge_sorted_arrays(arr, left, mid, right);
    }
}
void merge_sorted_arrays(int *arr, int left, int mid, int right)
{
    int left_length = mid - left + 1;
    int right_length = right - mid;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (int i = 0; i < left_length; i++)
        temp_left[i] = arr[left + i];

    for (int i = 0; i < right_length; i++)
        temp_right[i] = arr[mid + 1 + i];

    for (i = 0, j = 0, k = left; k <= right; k++)
    {

        if ((i < left_length) &&
            (j >= right_length || temp_left[i] <= temp_right[j]))
        {
            arr[k] = temp_left[i];
            i++;
        }

        else
        {
            arr[k] = temp_right[j];
            j++;
        }
    }
}
