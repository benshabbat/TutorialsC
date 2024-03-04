#include <stdio.h>
int binary_search(int *arr, int size, int num)
{
    int low = 0;
    int high = size - 1;
    while (low < high)
    {
        int middle = (low + high) / 2;
        if (arr[middle] == num)
            return middle;
        else if (arr[middle] > num)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 8, 9, 11, 22, 33, 44, 59, 68, 97};
    int i = binary_search(arr, sizeof(arr) / sizeof(arr[0]), 12);
    printf("%d\n", i);
    return 0;
}