#include <stdio.h>
#include <stdlib.h>

int *counting_sort(int *a, int size)
{
    int max = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    int *c_arr = (int *)calloc(max + 1, sizeof(int)); // Allocate memory for the count array
    if (c_arr == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        c_arr[a[i]]++; // Increment the count for the current element
    }

    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < c_arr[i]; j++)
        {
            a[index++] = i; // Fill the original array with sorted elements
        }
    }

    free(c_arr); // Free the memory allocated for the count array
    return a;
}

int main()
{
    int arr[] = {2, 3, 4, 5, 2, 1, 1, 1, 4, 4, 7, 7, 8, 8, 9, 9, 9, 6, 6, 2, 2, 3, 3, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    counting_sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("arr[%d]=%d\n", i, arr[i]);
    }

    return 0;
}