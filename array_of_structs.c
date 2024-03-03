#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

int main()
{
    int size = 5;
    Point *point;
    point = malloc(sizeof(Point));

    point->x = 100;
    point->y = 25;

    printf("%d\n", point->x);
    printf("%d\n", point->y);

    Point *points = malloc(sizeof(Point) * size);
    for (int i = 0; i < size; i++)
    {
        points[i].x = 100 * i;
        points[i].y = 20 * i;
    }
    for (int i = 0; i < size; i++)
    {
        printf("x=%d\n", points[i].x);
        printf("y=%d\n", points[i].y);
    }
    printf("\n\n after realloc");
    points = realloc(points, sizeof(Point) * (size * 2));
    for (int i = 0; i < size * 2; i++)
    {
        points[i].x = 100 * i;
        points[i].y = 20 * i;
    }
    for (int i = 0; i < size*2; i++)
    {
        printf("x=%d\n", points[i].x);
        printf("y=%d\n", points[i].y);
    }

    free(points);

    return 0;
}
