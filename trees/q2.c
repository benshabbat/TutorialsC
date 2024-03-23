#include "Question.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Node structure for a binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to get data of node
int getData(struct TreeNode* node) {
    if(node == NULL)
        return -1;
    return node->data;
}

// Function to insert leftNode for node
struct TreeNode* insertLeftNode(struct TreeNode* node, int data) {
    if (node == NULL)
        return NULL;
    struct TreeNode* left = createNode(data);
    node->left = left;
    return left;
}

// Function to insert rightNode for node
struct TreeNode* insertRightNode(struct TreeNode* node, int data) {
    if (node == NULL)
        return NULL;
    struct TreeNode* right = createNode(data);
    node->right = right;
    return right;
}

// Function to traverse the tree in preorder
void preOrderTraversal(struct TreeNode* root, int* result, int* index){
    // Complete the implementation here:
    // START
    
    // END
}

// Function to traverse the tree in inorder
void inOrderTraversal(struct TreeNode* root, int* result, int* index) {
    // Complete the implementation here:
    // START

    // END
}

// Function to traverse the tree in postorder
void postOrderTraversal(struct TreeNode* root, int* result, int* index) {
    // Complete the implementation here:
    // START

    // END
}