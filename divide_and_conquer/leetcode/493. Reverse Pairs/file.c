int merge(int* nums, int start, int mid, int end) {
    int count = 0;
    int j = mid + 1;

    for (int i = start; i <= mid; i++) {
        while (j <= end && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += j - (mid + 1);
    }

    // Merge the two sorted halves
    int* temp = (int*)malloc((end - start + 1) * sizeof(int));
    int i = start, k = 0;
    j = mid + 1;

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    while (j <= end) {
        temp[k++] = nums[j++];
    }

    for (i = 0; i < k; i++) {
        nums[start + i] = temp[i];
    }

    free(temp);
    return count;
}

int mergeSort(int* nums, int start, int end) {
    if (start >= end) {
        return 0;
    }

    int mid = start + (end - start) / 2;
    int count = 0;

    count += mergeSort(nums, start, mid);
    count += mergeSort(nums, mid + 1, end);
    count += merge(nums, start, mid, end);

    return count;
}

int reversePairs(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 1) {
        return 0;
    }

    return mergeSort(nums, 0, numsSize - 1);
}