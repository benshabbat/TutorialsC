/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSubPathUtil(struct ListNode* listNode, struct TreeNode* treeNode) {
    // If the linked list has reached the end, return true
    if (!listNode)
        return true;
    // If the tree node is NULL, return false
    if (!treeNode)
        return false;
    // If the values don't match, return false
    if (listNode->val != treeNode->val)
        return false;
    // Recursively check if the next nodes match
    return isSubPathUtil(listNode->next, treeNode->left) || isSubPathUtil(listNode->next, treeNode->right);
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    // If linked list is empty, it is always a subpath
    if (!head)
        return true;
    // If tree is empty, there cannot be a subpath
    if (!root)
        return false;
    // Check if the current subtree matches the linked list starting from head
    if (isSubPathUtil(head, root))
        return true;
    // If not, recursively check in the left and right subtrees
    return isSubPath(head, root->left) || isSubPath(head, root->right);
}