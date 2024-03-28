/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;

    // Initialize result array with 0s
    for (int i = 0; i < temperaturesSize; i++) {
        result[i] = 0;
    }

    // Stack to store indices of temperatures
    int stack[temperaturesSize];
    int top = -1;

    // Iterate over temperatures array
    for (int i = 0; i < temperaturesSize; i++) {
        while (top > -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            result[idx] = i - idx;
        }
        stack[++top] = i;
    }

    return result;
}