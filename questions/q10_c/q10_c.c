/*
Write a function:
bool is_ends_with(uint8_t * a, size_t a_size, uint8_t * b, size_t b_size)
That receives two arrays: a and b,
and returns true if a ends with b, otherwise false.
For example:

 a = 1,2,3,5,74,8,0,6,13,0  ; b = 0,6,13,0; // --> returns true

a = 1,2,3,5,74,8,0,6,0,0  ; b = 0,6,13,0; // --> returns false

Don't use the a[i] operator at all, just pointer arithmetics.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

bool is_ends_with(uint8_t *a, size_t a_size, uint8_t *b, size_t b_size)
{
    // TODO
    bool flag = true;
    int count_a = 0;
    int count_b = 0;
    // uint8_t *current;
    if (a_size > b_size)
    {
        for (int i = a_size - b_size; i < a_size; i++)
        {
            if (*a + i != (*b + count_b))
            {
                return flag = false;
            }
            count_b++;
        }
    }
    else if (a_size < b_size)
    {
        for (int i = b_size - a_size; i < b_size; i++)
        {
            if (*b + i != (*a + count_a))
            {
                return flag = false;
            }
            count_a++;
        }
    }
    else if (a_size == b_size)
    {

        for (int i = 0; i < b_size; i++)
        {
            if (*b + i != *a + i)
            {
                return flag = false;
            }
            // count_a++;
        }
    }
    return flag;
}
// option 2 better
bool is_ends_with(uint8_t *a, size_t a_size, uint8_t *b, size_t b_size)
{

    uint8_t *a_end = a + a_size;
    uint8_t *b_end = b + b_size;
    if (b_size > a_size)
    {
        while (a_size > 0)
        {
            if (*(--a_end) != *(--b_end))
            {
                return false;
            }
            a_size--;
        }
    }
    else
    {

        while (b_size > 0)
        {
            if (*(--a_end) != *(--b_end))
            {
                return false;
            }
            b_size--;
        }
    }

    return true;
}
int main()
{
    size_t a_size, b_size;

    // Note: The following printf commands are commented out since they
    //       confuse the auto testing of the output. However, you may find
    //       them useful for development needs.
    //       Don't forget to comment out when you submit :)

    // printf("Enter the size of array a: ");
    scanf("%zu", &a_size);
    uint8_t a[a_size];

    // printf("Enter the elements of array a:\n");
    for (size_t i = 0; i < a_size; i++)
    {
        scanf("%hhu", &a[i]);
    }

    // printf("Enter the size of array b: ");
    scanf("%zu", &b_size);
    uint8_t b[b_size];

    // printf("Enter the elements of array b:\n");
    for (size_t i = 0; i < b_size; i++)
    {
        scanf("%hhu", &b[i]);
    }

    bool result = is_ends_with(a, a_size, b, b_size);
    printf("%s", result ? "True" : "False");

    return 0;
}
