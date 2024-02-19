#include <stdio.h>
#include <stdlib.h>

// Define a struct for a point
typedef struct {
    int x;
    int y;
} Point;

int main() {
    int num_points = 3;

    // Dynamically allocate memory for the array of structs
    Point* points = (Point*)malloc(num_points * sizeof(Point));

    if (points == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the array elements
    for (int i = 0; i < num_points; i++) {
        points[i].x = i + 1;
        points[i].y = (i + 1) * 2;
    }

    // Print the array elements
    for (int i = 0; i < num_points; i++) {
        printf("Point %d: (%d, %d)\n", i + 1, points[i].x, points[i].y);
    }

    // Free the dynamically allocated memory
    free(points);

    return 0;
}