#include "Question.h"
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a > b) ? (a) : (b))

// Node structure for a binary tree
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode *createNode(int data, struct TreeNode *left, struct TreeNode *right)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->left = left;
    newNode->right = right;

    return newNode;
}

// Function to get data of node
int getData(struct TreeNode *node)
{
    if (node == NULL)
        return -1;
    return node->data;
}

// Function to insert leftNode for node
struct TreeNode *insertLeftNode(struct TreeNode *node, int data)
{
    if (node == NULL)
        return NULL;
    struct TreeNode *left = createNode(data, NULL, NULL);
    node->left = left;
    return left;
}

// Function to insert rightNode for node
struct TreeNode *insertRightNode(struct TreeNode *node, int data)
{
    if (node == NULL)
        return NULL;
    struct TreeNode *right = createNode(data, NULL, NULL);
    node->right = right;
    return right;
}
// Function to get depth of the tree rooted in root
int getDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    // Complete the implementation here:
    // START
    else
    {
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    // END
}

int diameterOfBinaryTree(struct TreeNode *root)
{
    // Complete the implementation here:
    // START
    if (root == NULL)
        return 0;

    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    return max(leftDepth + rightDepth, max(leftDiameter, rightDiameter));
    // END
}