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
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

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
    struct TreeNode *left = createNode(data);
    node->left = left;
    return left;
}

// Function to insert rightNode for node
struct TreeNode *insertRightNode(struct TreeNode *node, int data)
{
    if (node == NULL)
        return NULL;
    struct TreeNode *right = createNode(data);
    node->right = right;
    return right;
}

// Function to get number of node in tree rooted in root
int getNumOfNodes(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    // Complete the implementation here:
    // START
    if (root == NULL)
        return 0;
    else
        return 1 + getNumOfNodes(root->left) + getNumOfNodes(root->right);
    // END
}

// Function to get number of leaves in tree rooted in root
int getNumOfLeaves(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    // Complete the implementation here:
    // START
    else if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return getNumOfLeaves(root->left) + getNumOfLeaves(root->right);
    // END
}

// Function to get depth of the tree rooted in root
int getDepth(struct TreeNode *root)
{
    if (root == NULL)
        return -1;

    // Complete the implementation here:
    // START
    else {
        return max(getDepth(root->left), getDepth(root->right))+1;
    }
    // END
}