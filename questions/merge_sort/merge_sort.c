#include "Question.h"
#include <string.h>

void merge(int arr[], int left, int mid, int right)
{
    // Merge arr[left:mid] and arr[mid+1:right] in a sorted way
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int a[n1], b[n2];
    memcpy(a, &arr[left], sizeof(int) * n1);
    memcpy(b, &arr[mid + 1], sizeof(int) * n2);
    // Complete the implementation here:
    // START
    i = 0;
    j = 0;
    k = 0;
    for (; k < n1 + n2; k++)
    {
        if (i < n1 && j < n2)
        {

            if (a[i] < b[j])
            {
                arr[k] = a[i++];
            }
            else
            {
                arr[k] = b[j++];
            }
        }
        else break;
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