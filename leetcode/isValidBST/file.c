/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBSTUtil(struct TreeNode* root, long min, long max) {
    if (root == NULL) return true;
    if (root->val <= min || root->val >= max) return false;
    return isValidBSTUtil(root->left, min, root->val) && isValidBSTUtil(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
}