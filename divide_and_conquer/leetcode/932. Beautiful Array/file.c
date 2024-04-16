/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* beautifulArray(int n, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    if (n == 1) {
        result[0] = 1;
        return result;
    }
    
    int i, j, k;
    int* left = beautifulArray((n + 1) / 2, &i);
    int* right = beautifulArray(n / 2, &j);
    
    for (i = 0; i < (n + 1) / 2; i++) {
        result[i] = left[i] * 2 - 1;
    }
    for (j = 0; j < n / 2; j++) {
        result[i + j] = right[j] * 2;
    }
    
    free(left);
    free(right);
    return result;
}