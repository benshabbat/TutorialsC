#include "Question.h"
void swap(int *x, int *y)
{
    int temp =*x;
    *x = *y;
    *y = temp;
}
// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low;     // Index of smaller element

    // Complete the implementation here:
    // START
    for (int j = low; j< high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[high]);
    // END
    return i;
}

// Function to implement QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Get the partition index
        int pi = partition(arr, low, high);

        // Complete the implementation here:
        // START
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
        // END
    }
}
