#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);

    if (result != NULL) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *returnArr = malloc(2*sizeof(int));
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
          if(nums[i]+nums[j]==target){
            *returnSize = 2;
            returnArr[0]=i;
            returnArr[1]=j;
            return returnArr;
          }
      }
    }
    free(returnArr);
    *returnSize = 0;
    return returnArr;
}
