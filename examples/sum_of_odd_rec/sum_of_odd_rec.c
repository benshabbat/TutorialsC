#include <stdio.h>

int sum_of_odd_rec(int *arr, int length)
{
    if (length == 0)
        return 0;
    else if (arr[length - 1] % 2 == 1)
        return arr[length - 1] + sum_of_odd_rec(arr, length - 1);
    return sum_of_odd_rec(arr, length - 1);
}

int main()
{
    int arrr[] = {1, 11, 23, 45, 22, 33, 65, 65, 98, 45};
    printf("%d\n", sum_of_odd_rec(arrr, sizeof(arrr) / sizeof(arrr[0])));
    return 0;
}