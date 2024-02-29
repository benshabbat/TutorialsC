#include "Question.h"

// Function to merge two sorted arrays and count inversions
long long mergeAndCount(int arr[], int left, int mid, int right) {
    long long count=0;
    // Complete the implementation here:
    // START
    int i,j,k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

        int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            count++;
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    // END

    return count;
}

// Recursive function to perform merge sort and count inversions
long long mergeSortAndCount(int arr[], int left, int right) {
    long long count = 0;
    // Complete the implementation here:
    // START
    if (left < right) {
        int mid = (left + right) / 2;
        count+=mergeSortAndCount(arr, left, mid);
        count+=mergeSortAndCount(arr, mid + 1, right);
        count+=mergeAndCount(arr, left, mid, right);
    }
    // END
    return count;
}

// Function to initialize the merge sort process
long long countInversions(int arr[], int n) {
    long long result = mergeSortAndCount(arr, 0, n - 1);
    return result;
}
