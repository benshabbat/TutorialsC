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
    
}

int main()
{
    Node *head = NULL;
    Node *new_node = create_Node(4);

    printf("%d\n", new_node->value);

    return 0;
}