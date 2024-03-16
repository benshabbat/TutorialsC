#include "Question.h"
#include <stdlib.h>


#define MAX_SIZE 100

struct Queue {
    int front, rear;
    int array[MAX_SIZE];
};

// Function to initialize an empty queue
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue an element to the queue
void enqueue(struct Queue *queue, int item) {
    if (isFull(queue)) {
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        return -1; // Assuming -1 is not a valid element in the queue
    }

    int item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        // Reset the queue to empty state after the last element is dequeued
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return item;
}

// Function to get the front element of the queue without dequeueing
int front(struct Queue *queue) {
    if (isEmpty(queue)) {
        return -1; // Assuming -1 is not a valid element in the queue
    }
    return queue->array[queue->front];
}

int firstUniqueCharacter(const char *s) {
    // Complete the implementation here:
    // START

    // END
}