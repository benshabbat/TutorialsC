#include <stdio.h>
#include <stdlib.h>
#include <Question.h>

#define MAX_SIZE 500

// Structure to represent a priority queue
struct PriorityQueue {
    int heap[MAX_SIZE];
    int size;
};

// Function to create a priority queue
struct PriorityQueue *createPriorityQueue() {
    struct PriorityQueue *newNode = (struct PriorityQueue *) malloc(sizeof(struct PriorityQueue));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->size = 0;
    return newNode;
}

// Function to return the size of the priority queue
int getSize(struct PriorityQueue *pq) {
    return pq->size;
}

// Function to swap two elements in the heap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the heap property (min-heap)
void heapifyUp(struct PriorityQueue *pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->heap[index] < pq->heap[parent]) {
            swap(&pq->heap[index], &pq->heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Function to maintain the heap property (min-heap)
void heapifyDown(struct PriorityQueue *pq, int index) {
    while (2 * index + 1 < pq->size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = leftChild;

        if (rightChild < pq->size && pq->heap[rightChild] < pq->heap[leftChild]) {
            smallest = rightChild;
        }

        if (pq->heap[index] > pq->heap[smallest]) {
            swap(&pq->heap[index], &pq->heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Function to insert an element into the priority queue
void enqueue(struct PriorityQueue *pq, int value) {
    if (pq->size < MAX_SIZE) {
        pq->heap[pq->size] = value;
        heapifyUp(pq, pq->size);
        pq->size++;
    }
}

// Function to remove and return the minimum element from the priority queue
int dequeue(struct PriorityQueue *pq) {
    if (pq->size == 0)
        return -1;
    int minValue = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return minValue;
}

// Function to return the minimum element from the priority queue
int top(struct PriorityQueue *pq) {
    if (pq->size == 0)
        return -1;
    int minValue = pq->heap[0];
    return minValue;
}

int maxProduct(int *nums, int numsSize) {
    // int max1 = nums[0], max2 = nums[1];
    
    // if (max1 < max2) {
    //     int temp = max1;
    //     max1 = max2;
    //     max2 = temp;
    // }
    
    // for (int i = 2; i < numsSize; i++) {
    //     if (nums[i] >= max1) {
    //         max2 = max1;
    //         max1 = nums[i];
    //     } else if (nums[i] > max2) {
    //         max2 = nums[i];
    //     }
    // }
    
    // return (max1 - 1) * (max2 - 1);

    struct PriorityQueue *pq = createPriorityQueue();

    // Enqueue all elements into the priority queue
    for (int i = 0; i < numsSize; i++) {
        enqueue(pq, nums[i]*-1);
    }

    // Dequeue the two largest elements
    int max1 = dequeue(pq);
    int max2 = dequeue(pq);

    // Calculate and return the maximum product
    return (max1 + 1) * (max2 + 1);

}