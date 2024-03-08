#include <stdio.h>
#include <stdlib.h>

void counting_sort(int arr[], int n) {
    // Complete the implementation here:
    // START
    if (n <= 1) {
        return;
    }

    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a count array of size max+1 and initialize all elements to 0
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Store the count of each element in the count array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify the count array to store the sum of previous counts
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted output
    int *output = (int *)malloc(n * sizeof(int));

    // Traverse the input array from right to left
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements from the temporary array back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free dynamically allocated memory
    free(count);
    free(output);
    // END
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