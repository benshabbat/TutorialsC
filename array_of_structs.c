#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
    char *desc;
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
        points[i].desc = malloc(sizeof(char) * 10);
        strcpy(points[i].desc, "Point");
    }
    for (int i = 0; i < size; i++)
    {
        printf("x=%d\n", points[i].x);
        printf("y=%d\n", points[i].y);
        printf("Point %d=%s\n",i+1, points[i].desc);
    }
    printf("\n\n after realloc\n\n");
    points = realloc(points, sizeof(Point) * (size * 2));
    for (int i = 0; i < size * 2; i++)
    {
        points[i].x = 100 * i;
        points[i].y = 20 * i;
        points[i].desc = malloc(sizeof(char) * 10);
        strcpy(points[i].desc, "Point");
    }
    for (int i = 0; i < size * 2; i++)
    {
        printf("x=%d\n", points[i].x);
        printf("y=%d\n", points[i].y);
        printf("Point %d=%s\n",i+1, points[i].desc);
        free(points[i].desc);
    }

    free(points);

    return 0;
}
