#include "Question.h"

// Function definition - students are required to complete this function
int findSingle(int *nums, int numsSize)
{
    int result = 0;
    for (int i = 0; i < numsSize; i++)
    {
        result ^= nums[i];
    }
    return result;
}
