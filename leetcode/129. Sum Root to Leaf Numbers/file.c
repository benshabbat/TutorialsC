/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbersHelper(struct TreeNode* node, int currentSum) {
    if (node == NULL) {
        return 0;
    }
    
    // Calculate the sum up to the current node
    int newSum = currentSum * 10 + node->val;
    
    // If the current node is a leaf, return its value
    if (node->left == NULL && node->right == NULL) {
        return newSum;
    }
    
    // Recursively calculate the sum of left and right subtrees
    return sumNumbersHelper(node->left, newSum) + sumNumbersHelper(node->right, newSum);
}

int sumNumbers(struct TreeNode* root) {
    return sumNumbersHelper(root, 0);
}