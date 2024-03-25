#include <Question.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure to represent the answer
struct Tuple {
    int num_of_components, max_size;
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
    int num_of_components, max_size;
};

// Function to create a new disjoint set with 'n' elements
struct DisjointSet *createSet(int n) {
    struct DisjointSet *set = (struct DisjointSet *) malloc(sizeof(struct DisjointSet));
    set->parent = (int *) malloc(n * sizeof(int));
    set->rank = (int *) malloc(n * sizeof(int));
    set->size = (int *) malloc(n * sizeof(int));

    // Initialize each element as a separate set with rank 0
    for (int i = 0; i < n; ++i) {
        set->parent[i] = i;
        set->rank[i] = 0;
        set->size[i] = 1;
    }
    // Initialize the number of components to n
    set->num_of_components = n;
    // Initialize the maximum and minimum size to 1
    set->max_size = 1;

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
            set->size[rootY] += set->size[rootX];
            if (set->size[rootY] > set->max_size) {
                set->max_size = set->size[rootY];
            }

            // END
        } else if (set->rank[rootX] > set->rank[rootY]) {
            set->parent[rootY] = rootX;
            // Complete the implementation here:
            // START
            set->size[rootX] += set->size[rootY];
            if (set->size[rootX] > set->max_size) {
                set->max_size = set->size[rootX];
            }
            // END
        } else {
            // If ranks are the same, arbitrarily choose one as the root and increment its rank
            set->parent[rootX] = rootY;
            set->rank[rootY]++;
            // Complete the implementation here:
            // START
            set->size[rootY] += set->size[rootX];
            if (set->size[rootY] > set->max_size) {
                set->max_size = set->size[rootY];
            }
            // END
        }
        set->num_of_components--;
    }
}

struct Tuple *performQueries(int n, struct Query *queries, int numQueries) {
    struct DisjointSet *set = createSet(n);

    struct Tuple *result = (struct Tuple *) malloc(numQueries * sizeof(struct Tuple));
    // Complete the implementation here:
    // START
    for (int i = 0; i < numQueries; ++i) {
        struct Query q = queries[i];
        if (strcmp(q.type, "union") == 0) {
            unionSets(set, q.u, q.v);
            result[i].num_of_components = set->num_of_components;
            result[i].max_size = set->max_size;
        } else if (strcmp(q.type, "size") == 0) {
            int root = find(set, q.u);
            result[i].num_of_components = set->num_of_components;
            result[i].max_size = set->max_size;
        }
    }

    // END
    return result;
}

