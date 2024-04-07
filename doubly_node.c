#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
    struct Node* prev;
}Node;

Node* create_node(int value){
    Node* new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
}

Node* add_node(Node* head, int value){
    Node* new_node = create_node(value);
    if(head->next == NULL)
        return new_node;
    head->next = new_node;
    new_node->prev = head;
}