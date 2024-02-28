#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool has_two_numbers_with_sum(float *arr, int size, float num)
{
    int last_idx = size - 1;
    int first_idx = 0;
    while (first_idx < last_idx)
    {
        float sum = arr[first_idx] + arr[last_idx];

        if (sum == num)
        {
            return true;
        }
        else if (sum < num)
        {
            first_idx++;
        }
        else
        {
            last_idx--;
        }
    }
    return false;
}

int main()
{
    float num = 9.5;
    float arr[4] = {4, 5, 5.5, 6};
    bool res = has_two_numbers_with_sum(arr, 4, num);
    if (res)
    {

        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}