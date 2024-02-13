#include <stdio.h>

typedef union
{
    struct
    {
        int x;
        int y;
    };
    int coords[2];
} Point;

int main()
{
    Point p;

    // Read point values from stdin
    scanf("%d %d", &p.x, &p.y);

    // Calculate and print the sum using array notation
    int sum = p.coords[0] + p.coords[1];
    printf("%d\n", sum);

    return 0;
}
