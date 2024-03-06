#include <stdio.h>

int maxAscendingSum(int* nums, int numsSize) {
    int max_sum = nums[0];
    int current_sum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            current_sum += nums[i];
        } else {
            current_sum = nums[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

int main() {
    int nums[] = {10, 20, 30, 5, 10, 50};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", maxAscendingSum(nums, numsSize)); // Output: 65

    return 0;
}