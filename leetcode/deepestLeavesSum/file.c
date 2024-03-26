/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Helper function to perform a depth-first search
void dfs(struct TreeNode* node, int depth, int* deepestLevel, int* sum) {
    if (!node) return;
    
    // Update deepest level seen so far
    if (depth > *deepestLevel) {
        *deepestLevel = depth;
        *sum = 0; // Reset sum for new deepest level
    }
    
    // If current node is at the deepest level, add its value to sum
    if (depth == *deepestLevel) {
        *sum += node->val;
    }
    
    // Recur for left and right subtrees
    dfs(node->left, depth + 1, deepestLevel, sum);
    dfs(node->right, depth + 1, deepestLevel, sum);
}

int deepestLeavesSum(struct TreeNode* root) {
    int deepestLevel = 0;
    int sum = 0;
    dfs(root, 0, &deepestLevel, &sum);
    return sum;
}

//option 2 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* node) {
    if (node == NULL) return 0;
    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

void deepestLeavesSumHelper(struct TreeNode* node, int currentDepth, int targetDepth, int* sum) {
    if (node == NULL) return;
    
    if (currentDepth == targetDepth) {
        *sum += node->val;
        return;
    }
    
    deepestLeavesSumHelper(node->left, currentDepth + 1, targetDepth, sum);
    deepestLeavesSumHelper(node->right, currentDepth + 1, targetDepth, sum);
}

int deepestLeavesSum(struct TreeNode* root) {
    if (root == NULL) return 0;
    
    int depth = maxDepth(root);
    int sum = 0;
    deepestLeavesSumHelper(root, 1, depth, &sum);
    
    return sum;
}