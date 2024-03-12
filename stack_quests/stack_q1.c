#include "Question.h"
#include <stdlib.h>

#define MAX_SIZE 100 // keep it 100

struct Stack {
    int top;
    int array[MAX_SIZE];
};

// Function to initialize an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    // Complete the implementation here:
    // START
    return stack->top == -1;
    // END
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    // Complete the implementation here:
    // START
    return stack->top == MAX_SIZE-1;
    // END
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        return;
    }
    // Complete the implementation here:
    // START
    stack->array[++stack->top] = item;
    // END
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Assuming -1 is not a valid element in the stack
    }
    // Complete the implementation here:
    // START
    int item = stack->array[stack->top--];
    return item;
    // END
}

// Function to get the top element of the stack without popping
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Assuming -1 is not a valid element in the stack
    }
    // Complete the implementation here:
    // START
    return stack->array[stack->top];
    // END
}