int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0];
    int count = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    // At this point, `candidate` contains a potential majority element.
    // Verify if it's the majority element.
    count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }
    
    return (count > numsSize / 2) ? candidate : -1; // Return -1 if no majority element.
}