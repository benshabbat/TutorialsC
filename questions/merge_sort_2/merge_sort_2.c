#include "Question.h"
#include <stdbool.h>

bool isLessThan(const struct Point a, const struct Point b) {   
    // Comparator function to compare two points 
    // Should return true if Point a is less than Point b, 
    // (by lexicographical order)
    // Complete the implementation here:
    // START
    return (a.x<b.x)||(a.x==b.x&&a.y<b.y);
    // END
}

void merge(struct Point points[], int left, int mid, int right) {  
    // Merge points[left:mid] and points[mid+1:right] in a sorted way
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    struct Point L[n1], R[n2];
    // Complete the implementation here:
    // START

    for (i = 0; i < n1; i++)
        L[i] = points[left + i];
    for (j = 0; j < n2; j++)
        R[j] = points[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (isLessThan(L[i], R[j])) {
            points[k] = L[i++];
        } else {
            points[k] = R[j++];
        }
        k++;
    }

    while (i < n1) {
        points[k++] = L[i++];
    }

    while (j < n2) {
        points[k++] = R[j++];
    }
    // END
}

void mergeSort(struct Point arr[], int left, int right) {
    if (left < right) {
        // Complete the implementation here:
        // START
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
        // END
    }
}