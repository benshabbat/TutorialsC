#include <stdio.h>
void find_max_and_min(int *arr, int size)
{
    int max = arr[0], min = arr[0];
    if (size >= 1)
    {

        for (int i = 1; i < size; i++)
        {
            if (max < arr[i])
                max = arr[i];
            else if (min > arr[i])
                min = arr[i];
        }
    }
    printf("max = %d, min = %d\n", max,min);
}
int main()
{
    int arr[7] = {99, 55, 7777, 11, 44, 88, 66};
    find_max_and_min(arr, 7);
    return 0;
}