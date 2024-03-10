#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    struct Node *next;
} Node;

Node *create_Node(Node *node, int value)
{
    node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void add_Node(Node **head, Node *node)
{
}

int main()
{
    Node *head = NULL;
    Node *new_node = create_Node(new_node, 4);
    printf("%d\n", new_node->value);
    return 0;
}