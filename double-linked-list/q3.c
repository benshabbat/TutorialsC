#include "Question.h"
#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    char* str;
    int count;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(char* str) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->str = str;
    newNode->count = 1;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

char* getString(struct Node* node) {
    if(node == NULL)
        return NULL;
    return node->str;
}

int getCount(struct Node* node) {
    if(node == NULL)
        return 0;
    return node->count;
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
struct Node* insertAtEnd(struct Node* head, char* str) {
    struct Node* newNode = createNode(str);

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
struct Node* insertAtBeginning(struct Node* head, char* str) {
    struct Node* newNode = createNode(str);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a new node after a specific node in the doubly linked list
struct Node* insertAfter(struct Node* prevNode, char* str) {
    if (prevNode == NULL) {
        return NULL;
    }

    struct Node* newNode = createNode(str);

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
    if (head == NULL || Node == NULL) {
        return head;
    }

    if (head == Node) {
        head = Node->next;
    }

    if (Node->next != NULL) {
        Node->next->prev = Node->prev;
    }

    if (Node->prev != NULL) {
        Node->prev->next = Node->next;
    }

    free(Node);
    return head;
}

// Function to swap two nodes in the doubly linked list
struct Node* swapNodes(struct Node* head, struct Node* node1, struct Node* node2) {
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

    return head;
}

// Function increments the count of the given string, or adds it to the list if it doesn't exist
// The double linked list must be sorted in ascending order by count after the calling the function
struct Node* increment(struct Node* head, char* str){
    // Complete the implementation here:
    // START
    struct Node* current = head;

    // Search for the node with the given string
    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            // Node found, increment count and reposition if necessary
            current->count++;

            // Re-sort the list based on count
            while (current->prev != NULL && current->count < current->prev->count) {
                head = swapNodes(head, current, current->prev);
            }

            return head;
        }
        current = current->next;
    }

    // If the string is not found, add it to the list
    head = insertAtEnd(head, str);

    // Re-sort the list based on count
    current = head;
    while (current->next != NULL && current->count > current->next->count) {
        head = swapNodes(head, current, current->next);
    }

    return head;
    // END
}

// Function decrements the count of the given string, or removes it from the list if it reaches 0
// The double linked list must be sorted in ascending order by count after the calling the function
struct Node* decrement(struct Node* head, char* str){
    // Complete the implementation here:
    // START

    // END
}

// Function returns the string with the lowest count
char* getMinString(struct Node* head){
    // Complete the implementation here:
    // START

    // END
}

// Function returns the string with the highest count
char* getMaxString(struct Node* head){
    // Complete the implementation here:
    // START

    // END
}
