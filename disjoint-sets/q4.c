#include <stdlib.h>
#include <stdio.h>

// Structure to represent a query
struct Query
{
    char type;
    int x;
};

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
    set->parent = (int *)malloc((n + 1) * sizeof(int));
    set->rank = (int *)malloc(n * sizeof(int));
    set->size = n;

    // Initialize each element as a separate set with rank 0
    for (int i = 0; i < n; ++i)
    {
        set->parent[i] = i;
        set->rank[i] = 0;
    }
    set->parent[n] = -1;

    return set;
}

// Function to find the representative (root) of the set to which 'x' belongs
int find(struct DisjointSet *set, int x)
{
    // Complete the implementation here:
    // START
    if (set->parent[x] != x)
    {
        // Path compression: Make the parent of x point to the representative
        set->parent[x] = find(set, set->parent[x]);
    }
    return set->parent[x];
    // END
}

// Function to check the sets containing elements 'x' and 'y' are same
int isSameSet(struct DisjointSet *set, int x, int y)
{
    int rootX = find(set, x);
    int rootY = find(set, y);
    return rootX == rootY;
}

// Function to union the sets containing elements 'x' and 'y'
void unionSets(struct DisjointSet *set, int x, int y)
{
    // Complete the implementation here:
    // START

    int rootX = find(set, x);
    int rootY = find(set, y);

    if (rootX != rootY)
    {
        // Union by rank: Attach the shorter tree to the root of the taller tree
        if (set->rank[rootX] < set->rank[rootY])
        {
            int temp = rootX;
            rootX = rootY;
            rootY = temp;
        }
        set->parent[rootY] = rootX;
        if (set->rank[rootX] == set->rank[rootY])
        {
            set->rank[rootX]++;
        }
    }

    // END
}

int *findNearestStandingPerson(int n, int m, struct Query *queries)
{
    // Complete the implementation here
    // START
    // Create a disjoint set to represent the positions of people
    struct DisjointSet *set = createSet(n);

    // Initialize an array to store the result
    int *result = (int *)malloc(m * sizeof(int));

    // Process each query
    for (int i = 0; i < m; ++i)
    {
        struct Query query = queries[i];
        if (query.type == '?')
        {
            // If the person is standing, union their position with the adjacent positions if they are also standing
            int pos = query.x - 1;
            if (pos > 0 && set->parent[pos - 1] != -1)
            {
                unionSets(set, pos, pos - 1);
            }
            if (pos < n - 1 && set->parent[pos + 1] != -1)
            {
                unionSets(set, pos, pos + 1);
            }
            set->parent[pos] = pos;
        }
        else if (query.type == '-')
        {
            // If the query is about finding the nearest standing person to 'x', find the representative of 'x'
            // which represents the nearest standing person
            int pos = query.x - 1;
            result[i] = find(set, pos) + 1;
        }
    }

    // Free the memory used by the disjoint set
    free(set->parent);
    free(set->rank);
    free(set);

    return result;

    // END
}
