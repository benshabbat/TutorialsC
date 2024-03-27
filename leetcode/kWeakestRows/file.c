#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    // Allocate memory for the result array
    int* result = (int*)malloc(k * sizeof(int));
    if (!result) {
        *returnSize = 0;
        return NULL;
    }

    // Calculate the strength of each row
    int* arr = (int*)malloc(matSize * sizeof(int));
    if (!arr) {
        *returnSize = 0;
        free(result);
        return NULL;
    }

    for(int i = 0; i < matSize; i++) {
        int count = 0;
        for(int j = 0; j < matColSize[i]; j++) {
            if(mat[i][j] == 1) {
                count++;
            } else {
                break;
            }
        }
        arr[i] = count;
    }

    // Find the k weakest rows
    for (int i = 0; i < k; i++) {
        int minStrength = arr[0];
        int minIndex = 0;
        for (int j = 1; j < matSize; j++) {
            if (arr[j] < minStrength) {
                minStrength = arr[j];
                minIndex = j;
            }
        }
        result[i] = minIndex;
        arr[minIndex] = INT_MAX; // Mark this row as visited
    }

    // Clean up and return
    *returnSize = k;
    free(arr);
    return result;
}