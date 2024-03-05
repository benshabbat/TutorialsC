#include <stdio.h>

int sum(int arr[], int start, int end) {
    if (start == end) {
        return arr[start];
    } else {
        int mid = (start + end) / 2;
        int left_sum = sum(arr, start, mid);
        int right_sum = sum(arr, mid + 1, end);
        return left_sum + right_sum;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = sum(arr, 0, n - 1);
    printf("Sum of array: %d\n", result);
    return 0;
}