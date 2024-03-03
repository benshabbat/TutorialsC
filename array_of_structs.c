#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

int main()
{
    Point *point;
    point = malloc(sizeof(Point));

    point->x = 100;
    point->y = 25;

    printf("%d\n", point->x);
    printf("%d\n", point->y);

    Point *points = malloc(sizeof(Point) * 5);
    for (int i = 0; i < 5; i++)
    {
        points[i].x = 100 * i;
        points[i].y = 20 * i;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("x=%d\n", points[i].x);
        printf("y=%d\n", points[i].y);
    }

    free(points);

    return 0;
}
