#include "Question.h"
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack
{
    int top;
    char array[MAX_SIZE];
};

// Function to initialize an empty stack
struct Stack *createStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to get the size of the stack
int getSize(struct Stack *stack)
{
    return stack->top + 1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char item)
{
    if (isFull(stack))
    {
        return;
    }

    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return '$'; // Assuming $ is not a valid element in the stack
    }

    int item = stack->array[stack->top--];
    return item;
}

// Function to get the top element of the stack without popping
char peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return '$'; // Assuming $ is not a valid element in the stack
    }
    return stack->array[stack->top];
}

char *removeStarsFromString(const char *str)
{
    // Complete the implementation here:
    // START
    struct Stack* stack = createStack();
    int len = strlen(str);
    for(int i =0;i<len;i++)
    {
        if (cmp(str[i], '*') == 0)
        {
            pop(stack);
        }
        push(stack, str[i]);
    }
    strcpy(str, stack);
    return str;
    // END
}