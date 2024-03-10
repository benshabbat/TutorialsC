#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    struct Node *next;
} Node;

Node *create_Node(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void add_Node(Node **head, Node *node)
{
    if (*head == NULL)
    {
        *head = node;
        return;
    }

    node->next = *head;
    *head = node;
}

int main()
{
    Node *head = NULL;
    Node *new_node = create_Node(4);
    Node *new_node2 = create_Node(6);

    printf("%d\n", new_node->value);
    printf("%d\n", new_node2->value);
    add_Node(&head, new_node);
    add_Node(&head, new_node2);

    // Print the value of the first node
    printf("%d\n", head->value);
    // Free the memory allocated for the nodes
    free(new_node);
    return 0;
}