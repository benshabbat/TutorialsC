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
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to insert a new node at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a new node after a specific node in the doubly linked list
struct Node* insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        return NULL;
    }

    struct Node* newNode = createNode(data);

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;

    return newNode;
}

// Function to delete a node from the doubly linked list
struct Node* deleteNode(struct Node* head, struct Node* Node) {
    // Complete the implementation here:
    // START
    if (head == NULL || Node == NULL) {
        return head;
    }
    
    if (head == Node) {
        head = Node->next;
    }
    if(Node==head->next){
        head->next=Node->next;
    }
    if(Node->next==NULL){
        Node->prev->next=NULL;
    }
    if(Node->next!=NULL){
        Node->prev->next=Node->next;
        Node->next->prev=Node->prev
    }
    
    free(Node);
    // END
    return head;
}

// Function to swap two nodes in the doubly linked list
struct Node* swapNodes(struct Node* head, struct Node* node1, struct Node* node2) {
    // Complete the implementation here:
    // START
    if (node1 == NULL || node2 == NULL) {
        return head;
    }

    if (node1 == head) {
        head = node2;
    } else if (node2 == head) {
        head = node1;
    }

    struct Node* temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;

    if(node1->prev == node1)
        node1->prev = node2;
    if(node2->prev == node2)
        node2->prev = node1;

    temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
    if(node1->next == node1)
        node1->next = node2;
    if(node2->next == node2)
        node2->next = node1;

    if (node1->next != NULL)
        node1->next->prev = node1;
    if (node1->prev != NULL)
        node1->prev->next = node1;
    if (node2->next != NULL)
        node2->next->prev = node2;
    if (node2->prev != NULL)
        node2->prev->next = node2;
    // END

    return head;
}
