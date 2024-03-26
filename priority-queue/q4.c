#include <stdio.h>
#include <stdlib.h>
#include <Question.h>
#define MAX_SIZE 100

// Structure to represent a pair (row index, count of ones)
struct Pair {
    int row;
    int count;
};

// Structure to represent a priority queue
struct PriorityQueue {
    struct Pair heap[MAX_SIZE];
    int size;
};

// Function to create a priority queue
struct PriorityQueue *createPriorityQueue() {
    struct PriorityQueue *newNode = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
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
void swap(struct Pair *a, struct Pair *b) {
    struct Pair temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the heap property (min-heap)
void heapifyUp(struct PriorityQueue *pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->heap[index].count < pq->heap[parent].count ||
            (pq->heap[index].count == pq->heap[parent].count && pq->heap[index].row < pq->heap[parent].row)) {
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

        if (rightChild < pq->size &&
            (pq->heap[rightChild].count < pq->heap[leftChild].count ||
             (pq->heap[rightChild].count == pq->heap[leftChild].count && pq->heap[rightChild].row < pq->heap[leftChild].row))) {
            smallest = rightChild;
        }

        if (pq->heap[index].count > pq->heap[smallest].count ||
            (pq->heap[index].count == pq->heap[smallest].count && pq->heap[index].row > pq->heap[smallest].row)) {
            swap(&pq->heap[index], &pq->heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Function to insert an element into the priority queue
void enqueue(struct PriorityQueue *pq, struct Pair value) {
    if (pq->size < MAX_SIZE) {
        pq->heap[pq->size] = value;
        heapifyUp(pq, pq->size);
        pq->size++;
    }
}

// Function to remove and return the minimum element from the priority queue
struct Pair dequeue(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        struct Pair nullPair = {-1, -1}; // Indicate an empty queue
        return nullPair;
    }

    struct Pair minValue = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return minValue;
}

// Function to return the minimum element from the priority queue
struct Pair top(struct PriorityQueue *pq) {
    struct Pair nullPair = {-1, -1}; // Indicate an empty queue
    if (pq->size == 0)
        return nullPair;

    struct Pair minValue = pq->heap[0];
    return minValue;
}

// Function to create a pair
struct Pair createPair(int row, int count) {
    struct Pair p;
    p.row = row;
    p.count = count;
    return p;
}

// Function to compare two pairs
int comparePairs(const void *a, const void *b) {
    return ((struct Pair *)a)->count - ((struct Pair *)b)->count;
}

int *kWeakestRows(int **mat, int matSize, int *matColSize, int k, int *returnSize) {
    struct PriorityQueue *pq = createPriorityQueue();

    // Insert rows into the priority queue based on their count of ones
    for (int i = 0; i < matSize; i++) {
        int count = 0;
        for (int j = 0; j < *matColSize; j++) {
            if (mat[i][j] == 1) {
                count++;
            }
        }
        enqueue(pq, createPair(i, count));
    }

    // Retrieve the k weakest rows from the priority queue
    int *result = (int *)malloc(k * sizeof(int));
    *returnSize = k;
    for (int i = 0; i < k; i++) {
        struct Pair weakest = dequeue(pq);
        result[i] = weakest.row;
    }

    free(pq);
    return result;
}
