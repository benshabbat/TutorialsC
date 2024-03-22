#include "Question.h"
#include <stdlib.h>

// Structure to represent a disjoint set
struct DisjointSet {
    int *parent;
    int *rank;
    int size;
};

// Function to create a new disjoint set with 'n' elements
struct DisjointSet* createSet(int n) {
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->parent = (int*)malloc(n * sizeof(int));
    set->rank = (int*)malloc(n * sizeof(int));
    set->size = n;

    // Initialize each element as a separate set with rank 0
    for (int i = 0; i < n; ++i) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }

    return set;
}

// Function to find the representative (root) of the set to which 'x' belongs using Path compression
int find(struct DisjointSet* set, int x) {
    // Complete the implementation here:
    // START

    // END
}

// Function to check the sets containing elements 'x' and 'y' are same
bool isSameSet(struct DisjointSet* set, int x, int y) {
    // Complete the implementation here:
    // START

    // END
}

// Function to union the sets containing elements 'x' and 'y'
void unionSets(struct DisjointSet* set, int x, int y) {
    // Complete the implementation here:
    // START

    // END
}