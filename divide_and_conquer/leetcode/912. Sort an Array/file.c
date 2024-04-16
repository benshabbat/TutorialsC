/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void merge(int* nums, int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int* left = (int*)malloc(leftSize * sizeof(int));
    int* right = (int*)malloc(rightSize * sizeof(int));

    // Copy data to temp arrays left[] and right[]
    for (int i = 0; i < leftSize; i++) {
        left[i] = nums[start + i];
    }
    for (int j = 0; j < rightSize; j++) {
        right[j] = nums[mid + 1 + j];
    }

    // Merge the temp arrays back into nums[start..end]
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = start; // Initial index of merged subarray
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            nums[k] = left[i];
            i++;
        } else {
            nums[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < leftSize) {
        nums[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < rightSize) {
        nums[k] = right[j];
        j++;
        k++;
    }

    // Free memory
    free(left);
    free(right);
}

void mergeSort(int* nums, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Sort first and second halves
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);

        // Merge the sorted halves
        merge(nums, start, mid, end);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    if (numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    mergeSort(nums, 0, numsSize - 1);

    *returnSize = numsSize;
    return nums;
}