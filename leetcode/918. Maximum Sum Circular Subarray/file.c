int maxSubarraySumCircular(int* nums, int numsSize) {
    int max_sum_linear = kadane(nums, numsSize);

    // If all numbers are negative, max_sum_linear would be the answer
    if (max_sum_linear <= 0)
        return max_sum_linear;

    int total_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
        nums[i] = -nums[i]; // Invert the numbers
    }

    // Find the minimum subarray sum of the inverted array
    int max_sum_circular = total_sum + kadane(nums, numsSize);

    // Return the maximum of linear and circular subarray sums
    return max_sum_linear > max_sum_circular ? max_sum_linear : max_sum_circular;
}

int kadane(int* nums, int numsSize) {
    int max_sum = nums[0];
    int current_sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        current_sum = nums[i] > current_sum + nums[i] ? nums[i] : current_sum + nums[i];
        max_sum = current_sum > max_sum ? current_sum : max_sum;
    }
    return max_sum;
}