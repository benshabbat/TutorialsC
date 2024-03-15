#include "Question.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char array[MAX_SIZE];
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
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        return;
    }

    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Assuming -1 is not a valid element in the stack
    }

    char item = stack->array[stack->top--];
    return item;
}

// Function to get the top element of the stack without popping
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Assuming -1 is not a valid element in the stack
    }
    return stack->array[stack->top];
}


char* removeOuterParentheses(char* str) {
    char* ans = malloc(strlen(str) + 1);
    ans[0] = '\0';
    struct Stack* stack = createStack();
    int sz = (int) strlen(str);
    int count = 0;
    for(int i = 0 ; i < sz ; ++i) {
        char c = str[i];
        if (c == '(') {
            if (count > 0) {
                strcat(ans, "(");
            }
            push(stack, c);
            count++;
        } else if (c == ')') {
            count--;
            if (count > 0) {
                strcat(ans, ")");
            }
            if (isEmpty(stack)) {
                return ans; // Invalid parentheses sequence
            }
            pop(stack);
        }
    }
    free(stack);
    return ans;
}