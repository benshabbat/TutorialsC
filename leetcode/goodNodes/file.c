/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int countGoodNodes(struct TreeNode* root, int max_so_far) {
    if (root == NULL) {
        return 0;
    }

    int count = 0;
    if (root->val >= max_so_far) {
        count++;
        max_so_far = root->val;
    }

    count += countGoodNodes(root->left, max_so_far);
    count += countGoodNodes(root->right, max_so_far);

    return count;
}

int goodNodes(struct TreeNode* root) {
    return countGoodNodes(root, root->val);
}