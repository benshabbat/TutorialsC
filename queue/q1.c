#include "Question.h"
#include <stdlib.h>

#define MAX_SIZE 100 // keep it 100

struct Queue {
    int front, rear;
    int array[MAX_SIZE];
};

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    // Complete the implementation here:
    // START

    // END
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    // Complete the implementation here:
    // START

    // END
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    // Complete the implementation here:
    // START

    // END
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1; // Assuming -1 is not a valid element in the queue
    }
    // Complete the implementation here:
    // START

    // END
}

// Function to get the front element of the queue without dequeueing
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1; // Assuming -1 is not a valid element in the queue
    }
    // Complete the implementation here:
    // START

    // END
}