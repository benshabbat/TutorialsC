/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }

    // If the current node is a leaf node and its value is equal to the target sum,
    // then we've found a path from the root to a leaf with the target sum.
    if (root->left == NULL && root->right == NULL && root->val == targetSum) {
        return true;
    }

    // Recursively check if there is a path with the target sum in the left or right subtree.
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}