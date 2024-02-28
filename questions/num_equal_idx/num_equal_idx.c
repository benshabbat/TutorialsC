#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool has_num_equal_idx(int *arr,int size)
{
    int last_idx = size - 1;
    int first_idx = 0;
    while (first_idx < last_idx)
    {
        if (arr[first_idx] == first_idx)
        {
            return true;
        }
        first_idx++;

    }
    return false;
}

int main()
{
    int arr[6] = {1,2,2,8,9,10};
    bool res = has_num_equal_idx(arr,6);
    if (res)
    {
        printf("True");
    }
    else{
        printf("False");
    }

    return 0;
}