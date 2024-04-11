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
    free(stack->array);
    free(stack);
}

bool is_empty(Stack *stack)
{
    return stack->size == 0;
}

bool is_full(Stack *stack)
{
    return stack->size == stack->capacity;
}

bool push(Stack *stack, int item)
{
    if (is_full(stack))
        return false;
    stack->array[stack->size++] = item;
    return true;
}

bool pop(Stack *stack, int *item)
{
    if (is_empty(stack))
        return false;
    *item = stack->array[stack->size--];
    return true;
}
bool peek(Stack *stack, int *item)
{
    if (is_empty(stack))
        return false;
    *item = stack->array[stack->size - 1];
    return true;
}
int main()
{
    Stack *stack = create_stack(5);
    if(stack==NULL){
        printf("Stack error");
        return 1;
    }
    push(stack, 5);
    printf("%d\n", stack->size);
    printf("%d", stack->array[stack->size-1]);
    destroy_stack(stack);

    return 0;
}