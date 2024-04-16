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