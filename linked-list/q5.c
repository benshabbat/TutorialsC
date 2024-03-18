#include "Question.h"
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data, struct Node* next) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = next;

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
    struct Node* newNode = createNode(data, NULL);
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data, NULL);

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

struct Node* reverseBetween(struct Node* head, int left, int right) {
    // Complete the implementation here:
    // START
    if (head == NULL || left == right) {
        return head;
    }

    struct Node* dummy = createNode(-1, head);
    struct Node* prev = dummy;

    // Move prev to the node before the left position
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    struct Node* current = prev->next;
    struct Node* next;
    struct Node* tail = current;

    // Reverse the portion between left and right
    for (int i = left; i <= right; i++) {
        next = current->next;
        current->next = prev->next;
        prev->next = current;
        current = next;
    }

    // Connect the reversed portion with the rest of the list
    tail->next = current;

    return dummy->next;
    // END
}