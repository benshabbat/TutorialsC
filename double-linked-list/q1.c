#include "Question.h"
#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

int getData(struct Node* node) {
    if(node == NULL)
        return -1;
    return node->data;
}

struct Node* getNext(struct Node* node) {
    if(node == NULL)
        return NULL;
    return node->next;
}

struct Node* getPrev(struct Node* node) {
    if(node == NULL)
        return NULL;
    return node->prev;
}

// Function to insert a new node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {

    // Complete the implementation here:
    // START

    // END
}

// Function to insert a new node at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node* head, int data) {

    // Complete the implementation here:
    // START

    // END
}

// Function to insert a new node after a specific node in the doubly linked list
struct Node* insertAfter(struct Node* prevNode, int data) {

    // Complete the implementation here:
    // START

    // END
}
