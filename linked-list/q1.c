#include "Question.h"
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

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

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    // Complete the implementation here:
    // START
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
    // END
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    // Complete the implementation here:
    // START
    struct Node *newNode = createNode(data); 
    struct Node *curr = head;
    if (head == NULL) {
        return newNode;
    }

    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
    // END

}