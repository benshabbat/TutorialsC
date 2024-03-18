#include "Question.h"
#include <stdlib.h>


#define MAX_SIZE 1000

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

// Function to get the front element of the queue without dequeue
int front(struct Queue *queue) {
    if (isEmpty(queue)) {
        return -1; // Assuming -1 is not a valid element in the queue
    }
    return queue->array[queue->front];
}

// Function to destroy the queue and free allocated memory
void destroyQueue(struct Queue *queue) {
    free(queue);
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int *deckRevealedIncreasing(int *deck, int deckSize, int *returnSize) {
    // Complete the implementation here:
    // START
    // Sort the deck array in ascending order
    qsort(deck, deckSize, sizeof(int), compare);

    // Create a queue to store the indices of the sorted deck array
    struct Queue *queue = createQueue();

    // Initialize a result array with -1
    int *result = (int *)malloc(deckSize * sizeof(int));
    for (int i = 0; i < deckSize; i++) {
        result[i] = -1;
    }

    // Enqueue the indices of the sorted deck array
    for (int i = 0; i < deckSize; i++) {
        enqueue(queue, i);
    }

    // Simulate the revealing process
    int index = 0;
    while (!isEmpty(queue)) {
        int dequeuedIndex = dequeue(queue);
        result[dequeuedIndex] = deck[index++];
        if (!isEmpty(queue)) {
            enqueue(queue, dequeue(queue));
        }
    }

    // Set the returnSize pointer to the size of the result array
    *returnSize = deckSize;

    // Destroy the queue and return the result array
    destroyQueue(queue);
    return result;
    // END
}