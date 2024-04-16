int findKthLargest(int* nums, int numsSize, int k) {
    int arr[numsSize];
    int max= nums[0];
    arr[0]=max;
    int j=1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]>=max){
            arr[j++]=nums[i];
            max=nums[i];
        }
        
    }

    return arr[j-k];
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the index of the pivot element
int partition(int* nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }

    swap(&nums[i + 1], &nums[right]);
    return i + 1;
}

// Function to find the kth largest element using quickselect
int findKthLargest(int* nums, int numsSize, int k) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == numsSize - k) {
            return nums[pivotIndex];
        } else if (pivotIndex < numsSize - k) {
            left = pivotIndex + 1;
        } else {
            right = pivotIndex - 1;
        }
    }

    return -1; // This should not happen if k is valid
}
