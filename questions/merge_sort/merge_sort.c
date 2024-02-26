#include "Question.h"

void merge(int arr[], int left, int mid, int right)
{
    // Merge arr[left:mid] and arr[mid+1:right] in a sorted way
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int a[n1], b[n2];

    for (i = 0; i < n1; i++)
        a[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        b[j] = arr[mid + 1 + j];
    // Complete the implementation here:
    // START
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = b[i];
            i++;
        } else {
            arr[k] = a[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k++] = a[i++];
    }
    while (j < n2)
    {
        arr[k++] = b[j++];
    }
    // END
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        // Complete the implementation here:
        // START

        merge(arr, left, mid, right);

        // END
    }
}