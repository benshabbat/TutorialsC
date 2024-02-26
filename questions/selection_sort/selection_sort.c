#include "Question.h"

void sortArr(int arr[], int size, int iterations)
{
    for (int i = 0; i < size && iterations; ++i, iterations--)
    {
        int min_index = i;
        // complete selection sort implementation here:
        // taking the index for the min
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        // swap

        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;

        // START
        // END
    }
}