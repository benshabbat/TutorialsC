#include "Question.h"
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a disjoint set
struct DisjointSet
{
    int *parent;
    int *rank;
    int size;
};

// Function to create a new disjoint set with 'n' elements
struct DisjointSet *createSet(int n)
{
    struct DisjointSet *set = (struct DisjointSet *)malloc(sizeof(struct DisjointSet));
    set->parent = (int *)malloc(n * sizeof(int));
    set->rank = (int *)malloc(n * sizeof(int));
    set->size = n;

    // Initialize each element as a separate set with rank 0
    for (int i = 0; i < n; ++i)
    {
        set->parent[i] = i;
        set->rank[i] = 0;
    }

    return set;
}

// Function to find the representative (root) of the set to which 'x' belongs using Path compression
int find(struct DisjointSet *set, int x)
{
    // Complete the implementation here:
    // START
    if (set->parent[x] != x)
    {
        set->parent[x] = find(set, set->parent[x]);
    }
    return set->parent[x];
    // END
}

// Function to check the sets containing elements 'x' and 'y' are same
bool isSameSet(struct DisjointSet *set, int x, int y)
{
    // Complete the implementation here:
    // START
    int rootX = find(set, x);
    int rootY = find(set, y);
    return rootX == rootY;

    // return set->parent[x] == set->parent[y];
    // END
}

// Function to union the sets containing elements 'x' and 'y'
void unionSets(struct DisjointSet *set, int x, int y)
{
    // Complete the implementation here:
    // START
    int rootX = find(set, x);
    int rootY = find(set, y);

    // Union by rank: Attach the smaller rank tree under the root of the larger rank tree
    if (rootX != rootY)
    {
        if (set->rank[rootX] < set->rank[rootY])
        {
            set->parent[rootX] = rootY;
        }
        else if (set->rank[rootX] > set->rank[rootY])
        {
            set->parent[rootY] = rootX;
        }
        else
        {
            // If ranks are the same, arbitrarily choose one as the root and increment its rank
            set->parent[rootX] = rootY;
            set->rank[rootY]++;
        }
    }
    // END
}