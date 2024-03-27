/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000); // Assuming a maximum of 10000 nodes
    int front = 0, rear = 0;
    int* result = (int*)malloc(sizeof(int) * 10000); // Assuming a maximum of 10000 nodes
    *returnSize = 0;
    
    queue[rear++] = root;
    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            if (i == levelSize - 1) {
                result[(*returnSize)++] = node->val;
            }
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
    }
    
    free(queue);
    return result;
}


//example with queque

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct Queue* queue = createQueue();
    enQueue(queue, root);

    int* result = (int*)malloc(sizeof(int) * 1000); // Assuming a maximum of 1000 nodes
    int resultSize = 0;

    while (queue->front != NULL) {
        int levelSize = queue->rear - queue->front + 1;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = deQueue(queue);
            if (i == levelSize - 1) {
                result[resultSize++] = node->val; // Store the rightmost node at each level
            }
            if (node->left != NULL) {
                enQueue(queue, node->left);
            }
            if (node->right != NULL) {
                enQueue(queue, node->right);
            }
        }
    }

    *returnSize = resultSize;
    return result;
}