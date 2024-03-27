#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a priority queue
struct PriorityQueue {
    int heap[MAX_SIZE];
    int size;
};

// Function to create a priority queue
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* newNode = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->size = 0;
    return newNode;
}

// Function to return the size of the priority queue
int getSize(struct PriorityQueue* pq) {
    return pq->size;
}

// Function to swap two elements in the heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the heap property (min-heap)
void heapifyUpMin(struct PriorityQueue* pq, int index) {
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

// Function to maintain the heap property (max-heap)
void heapifyUpMax(struct PriorityQueue* pq, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pq->heap[index] > pq->heap[parent]) {
            swap(&pq->heap[index], &pq->heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

// Function to maintain the heap property (min-heap)
void heapifyDownMin(struct PriorityQueue* pq, int index) {
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

// Function to maintain the heap property (max-heap)
void heapifyDownMax(struct PriorityQueue* pq, int index) {
    while (2 * index + 1 < pq->size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = leftChild;

        if (rightChild < pq->size && pq->heap[rightChild] > pq->heap[leftChild]) {
            largest = rightChild;
        }

        if (pq->heap[index] < pq->heap[largest]) {
            swap(&pq->heap[index], &pq->heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

// Function to insert an element into the priority queue (min-heap)
void enqueueMin(struct PriorityQueue* pq, int value) {
    if (pq->size < MAX_SIZE) {
        pq->heap[pq->size] = value;
        heapifyUpMin(pq, pq->size);
        pq->size++;
    }
}

// Function to insert an element into the priority queue (max-heap)
void enqueueMax(struct PriorityQueue* pq, int value) {
    if (pq->size < MAX_SIZE) {
        pq->heap[pq->size] = value;
        heapifyUpMax(pq, pq->size);
        pq->size++;
    }
}

// Function to remove and return the minimum element from the priority queue (min-heap)
int dequeueMin(struct PriorityQueue* pq) {
    if(pq->size == 0)
        return -1;
    int minValue = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDownMin(pq, 0);
    return minValue;
}

// Function to remove and return the maximum element from the priority queue (max-heap)
int dequeueMax(struct PriorityQueue* pq) {
    if(pq->size == 0)
        return -1;
    int maxValue = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDownMax(pq, 0);
    return maxValue;
}

// Function to return the minimum element from the priority queue (min-heap)
int topMin(struct PriorityQueue* pq) {
    if(pq->size == 0)
        return -1;
    int minValue = pq->heap[0];
    return minValue;
}

// Function to return the maximum element from the priority queue (max-heap)
int topMax(struct PriorityQueue* pq) {
    if(pq->size == 0)
        return -1;
    int maxValue = pq->heap[0];
    return maxValue;
}

// Function to insert new integers to the empty list
void add(int value, struct PriorityQueue* minHeap, struct PriorityQueue* maxHeap){
    // Complete the implementation here:
    // START
    if(getSize(minHeap) == 0 && getSize(maxHeap) == 0){
        enqueueMin(minHeap, value);
    } else {
        if(value < topMin(minHeap)){
            enqueueMax(maxHeap, value);
        } else {
            enqueueMin(minHeap, value);
        }
    }

    if(getSize(minHeap) > getSize(maxHeap) + 1){
        int val = dequeueMin(minHeap);
        enqueueMax(maxHeap, val);
    }

    if(getSize(maxHeap) > getSize(minHeap) + 1){
        int val = dequeueMax(maxHeap);
        enqueueMin(minHeap, val);
    }
    
    // END
}

// Function to return the current median of the list
double getMedian(struct PriorityQueue* minHeap, struct PriorityQueue* maxHeap){
    double ret;
    // Complete the implementation here:
    // START
    if(getSize(minHeap) == 0 && getSize(maxHeap) == 0)
        return -1;

    if(getSize(minHeap) == getSize(maxHeap)){
        return (double)(topMin(minHeap) + topMax(maxHeap)) / 2;
    } else if(getSize(minHeap) > getSize(maxHeap)){
        return topMin(minHeap);
    } else {
        return topMax(maxHeap);
    }
    // END
    return ret;
}

// Function to return the array of medians
double* runningMedian(int arr[], int sz) {
    double* result = malloc(sizeof(double) * sz);

    struct PriorityQueue* minHeap = createPriorityQueue();
    struct PriorityQueue* maxHeap = createPriorityQueue();

    for(int i = 0; i < sz; i++){
        add(arr[i], minHeap, maxHeap);
        result[i] = getMedian(minHeap, maxHeap);
    }

    return result;
}