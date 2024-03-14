#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *array;
    int capacity;
    int size;
} Stack;

Stack *create_stack(int capacity)
{
    if (capacity <= 0)
        return NULL;
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
        return NULL;
    stack->array = malloc(capacity * sizeof(Stack));
    if (stack->array == NULL)
    {
        free(stack);
        return NULL;
    }
    stack->capacity = capacity;
    stack->size = 0;
    return stack;
}
void destroy_stack(Stack *stack)
{
    free(Stack->array);
    free(Stack);
}

bool is_empty(Stack *stack)
{
    return stack->size == 0;
}

bool is_full(Stack *stack)
{
    
}

bool push(Stack *stack, int item)
{
}

bool pop(Stack *stack, int *item)
{
}
bool peek(Stack *stack, int *item)
{
}
int main()
{
    return 0;
}