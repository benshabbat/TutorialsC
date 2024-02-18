#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    int *arr;
} Info;

int main()
{

    Info a;
    a.data = 4;
    a.arr = malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
    {
        a.arr[i] = i;
    }

    Info b = a;
    printf("%d\n", b.data);
    printf("%d\n", a.data);
    // free(a.arr);//if free(a.arr) b.arr free to;
    for (int i = 0; i < 5; i++)
    {
        printf("%d", b.arr[i]);
    }
    free(a.arr);

    return 0;
}