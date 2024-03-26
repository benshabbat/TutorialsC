/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // If the root is NULL or if either p or q is the root, the LCA is the root itself
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // Recursively find the LCA in the left and right subtrees
    struct TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    // If both left and right LCA are not NULL, then the current node is the LCA
    if (leftLCA && rightLCA) {
        return root;
    }

    // Otherwise, return the non-NULL LCA (if one exists)
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}