#include "Question.h"
#include <stdbool.h>
// Function to find the maximum number in the array
int getMax(int arr[], int n) {
    // Complete the implementation here:
    // START
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if (max<arr[i])max = arr[i];       
    }
    return max;
    // END
}

// Using counting sort to sort elements based on significant places
void countingSort(int arr[], int n, int exp) {
    const int RADIX = 10;
    int output[n];
    int count[RADIX];

    for(int i = 0 ; i < RADIX ; ++i)
        count[i] = 0;

    // Complete the implementation here:
    // START

    // END

    // Copy the sorted array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort implementation
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Perform counting sort for every digit place (1, 10, 100, ...)
    for (int exp = 1; max / exp > 0; exp *= 10) {
        // Complete the implementation here:
        // START

        // END
    }
}