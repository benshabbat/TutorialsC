/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inOrder(struct TreeNode* root, int* count, int k, int* result) {
    if (root == NULL) return;

    inOrder(root->left, count, k, result);

    (*count)++;
    if (*count == k) {
        *result = root->val;
        return;
    }

    inOrder(root->right, count, k, result);
}

int kthSmallest(struct TreeNode* root, int k) {
    int count = 0;
    int result = 0;
    inOrder(root, &count, k, &result);
    return result;
}