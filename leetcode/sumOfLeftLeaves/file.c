/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumOfLeftLeaves(struct TreeNode* root) {
        if (!root) {
        return 0;
    }

    int sum = 0;
    if (root->left) {
        if (!root->left->left && !root->left->right) {
            sum += root->left->val; // Add the value of the left leaf node
        } else {
            sum += sumOfLeftLeaves(root->left); // Recursively traverse the left subtree
        }
    }

    sum += sumOfLeftLeaves(root->right); // Recursively traverse the right subtree

    return sum;
}