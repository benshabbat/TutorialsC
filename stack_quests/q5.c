#include "Question.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

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
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        return;
    }

    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Assuming -1 is not a valid element in the stack
    }

    int item = stack->array[stack->top--];
    return item;
}

// Function to get the top element of the stack without popping
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Assuming -1 is not a valid element in the stack
    }
    return stack->array[stack->top];
}

int evaluateReversePolishNotation(char* tokens[], int tokensSize) {
    struct Stack* stack = createStack();
    // Complete the implementation here:
    // START
    for (int i = 0; i < tokensSize; i++) {
        if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
            // If the token is a number, push it onto the stack
            int num = atoi(tokens[i]);
            push(stack, num);
        } else {
            // If the token is an operator, pop the top two elements
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            int result;

            // Perform the operation
            switch (tokens[i][0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    // Invalid operator
                    return -1;
            }

            // Push the result back onto the stack
            push(stack, result);
        }
    }

    // The final result is at the top of the stack
    int finalResult = pop(stack);

    // Free the memory allocated for the stack
    free(stack);

    return finalResult;
    // END
}