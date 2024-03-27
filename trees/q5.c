#include "Question.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max(a, b) ((a > b) ? (a) : (b))

// Node structure for a binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data, struct TreeNode* left, struct TreeNode* right) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->left = left;
    newNode->right = right;

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
    struct TreeNode* left = createNode(data, NULL, NULL);
    node->left = left;
    return left;
}

// Function to insert rightNode for node
struct TreeNode* insertRightNode(struct TreeNode* node, int data) {
    if (node == NULL)
        return NULL;
    struct TreeNode* right = createNode(data, NULL, NULL);
    node->right = right;
    return right;
}


int deepestLeavesSum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    // Initialize variables for the sum of current level and the sum of deepest level
    int sum = 0, deepestSum = 0;
    struct TreeNode* current;
    struct TreeNode* queue[10000]; // Assuming the maximum number of nodes in the tree is 10000
    int front = -1, rear = -1;

    queue[++rear] = root;

    while (front != rear) {
        int levelSize = rear - front;

        sum = 0; // Reset sum for the current level
        for (int i = 0; i < levelSize; ++i) {
            current = queue[++front];
            sum += current->data;

            if (current->left != NULL) {
                queue[++rear] = current->left;
            }
            if (current->right != NULL) {
                queue[++rear] = current->right;
            }
        }

        // Update deepest sum
        deepestSum = sum;
    }

    return deepestSum;
}

