#include <stdio.h>

int find_min(int *myArr, int length);
int main(void)
{
    int myArr[] = {55, 8, 22, 77, 11, 55, 33, 66, 99, 1233, 321, 44, 7, 444};
    int length = sizeof(myArr) / sizeof(myArr[0]);
    int min = find_min(myArr, length);
    printf("%d\n", min);
    return 0;
}

int find_min(int *myArr, int length)
{
    int min = myArr[0];
    for (int i = 1; i <= length - 1; i++)
    {
        if (myArr[i] < min)
        {
            min = myArr[i];
        }
    }

    return min;
}
