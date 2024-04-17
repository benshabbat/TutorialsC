int mergeSort(long* sums, int start, int end, int lower, int upper) {
    if (start >= end) return 0;

    int mid = start + (end - start) / 2;
    int count = mergeSort(sums, start, mid, lower, upper) + mergeSort(sums, mid + 1, end, lower, upper);

    int j = mid + 1, k = mid + 1;
    for (int i = start; i <= mid; i++) {
        while (j <= end && sums[j] - sums[i] < lower) j++;
        while (k <= end && sums[k] - sums[i] <= upper) k++;
        count += k - j;
    }

    long* sorted = malloc((end - start + 1) * sizeof(long));
    int p = 0, p1 = start, p2 = mid + 1;
    while (p1 <= mid || p2 <= end) {
        if (p1 > mid) {
            sorted[p++] = sums[p2++];
        } else if (p2 > end) {
            sorted[p++] = sums[p1++];
        } else {
            if (sums[p1] < sums[p2]) {
                sorted[p++] = sums[p1++];
            } else {
                sorted[p++] = sums[p2++];
            }
        }
    }

    for (int i = start; i <= end; i++) {
        sums[i] = sorted[i - start];
    }

    free(sorted);

    return count;
}

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    long* sums = malloc((numsSize + 1) * sizeof(long));
    sums[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }

    int count = mergeSort(sums, 0, numsSize, lower, upper);

    free(sums);

    return count;
}
