#include <stdio.h>

int find_max(int *myArr, int length);

int main(void)
{
    int myArr[] = {55, 8, 22, 77, 11, 33, 66, 99, 1233, 321, 44, 7, 444};
    int length = sizeof(myArr) / sizeof(myArr[0]);
    int max = find_max(myArr, length);
    printf("%d\n", max);
    return 0;
}
int find_max(int *myArr, int length)
{
    int max = myArr[0];
    for (int i = 1; i <= length - 1; i++)
    {
        if (myArr[i] > max)
        {
            max = myArr[i];
        }
    }
    return max;
}