#include <Question.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure to represent the answer
struct Tuple {
    int min_element, max_element,set_size;
};

// Structure to represent the Query
struct Query {
    char type[10];
    int u, v;
};

// Structure to represent a disjoint set
struct DisjointSet {
    int *parent;
    int *rank;
    int *size;
    int *min_element;
    int *max_element;
};

// Function to create a new disjoint set with 'n' elements
struct DisjointSet *createSet(int n) {
    struct DisjointSet *set = (struct DisjointSet *) malloc(sizeof(struct DisjointSet));
    set->parent = (int *) malloc(n * sizeof(int));
    set->rank = (int *) malloc(n * sizeof(int));
    set->min_element = (int *) malloc(n * sizeof(int));
    set->max_element = (int *) malloc(n * sizeof(int));
    set->size = (int *) malloc(n * sizeof(int));

    // Initialize each element as a separate set with rank 0
    for (int i = 0; i < n; ++i) {
        set->parent[i] = i;
        set->rank[i] = 0;
        set->size[i] = 1;
        set->min_element[i] = i;
        set->max_element[i] = i;
    }

    return set;
}

// Function to find the representative (root) of the set to which 'x' belongs using Path compression
int find(struct DisjointSet *set, int x) {
    // Path compression: Set the parent of each traversed node directly to the root
    if (set->parent[x] != x) {
        set->parent[x] = find(set, set->parent[x]);
    }
    return set->parent[x];
}

// Function to check the sets containing elements 'x' and 'y' are same
int isSameSet(struct DisjointSet *set, int x, int y) {
    int rootX = find(set, x);
    int rootY = find(set, y);
    return rootX == rootY;
}

// Function to union the sets containing elements 'x' and 'y'
void unionSets(struct DisjointSet *set, int x, int y) {
    int rootX = find(set, x);
    int rootY = find(set, y);

    // Union by rank: Attach the smaller rank tree under the root of the larger rank tree
    if (rootX != rootY) {
        if (set->rank[rootX] < set->rank[rootY]) {
            set->parent[rootX] = rootY;
            // Complete the implementation here:
            // START


            // END
        } else if (set->rank[rootX] > set->rank[rootY]) {
            set->parent[rootY] = rootX;
            // Complete the implementation here:
            // START


            // END
        } else {
            // If ranks are the same, arbitrarily choose one as the root and increment its rank
            set->parent[rootX] = rootY;
            set->rank[rootY]++;
            // Complete the implementation here:
            // START


            // END
        }
    }
}

struct Tuple *performQueries(int n, struct Query *queries, int numQueries) {
    struct DisjointSet *set = createSet(n);

    struct Tuple *result = (struct Tuple *) malloc(numQueries * sizeof(struct Tuple));
    // Complete the implementation here:
    // START



    // END
    return result;
}


