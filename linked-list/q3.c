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

void setNext(struct Node* node, struct Node* nxt) {
    if(node == NULL)
        return;
    node->next = nxt;
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

struct Node* deleteMiddleNode(const struct Node* head) {
    // Complete the implementation here:
    // START
    if (head == NULL|| head->next == NULL) {
        return NULL;
    }
    struct Node *fast = head;
    struct Node *slow = head;
    struct Node *prevMiddle = slow;
    while (fast != NULL && fast->next != NULL)
    {
        prevMiddle=slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prevMiddle->next=slow->next;
    free(slow);
    
    return head;
  
    // END
}