/*
Write a function:
int find_in_array(int * a, size_t a_size, int what_to_search)
That returns the first index of “what_to_search” in the given array, or if it wasn’t found, returns –1.
*/

#include <stdio.h>
#include <stdint.h>

// int find_in_array(int *a, size_t a_size, int what_to_search)
// {
//     for (int i = 0; i < a_size; i++)
//     {
//         int *current = a + i;
//         if (what_to_search == *current)
//             return i;
//     }

//     return -1;
// }
//option2 
int find_in_array(int *a, size_t a_size, int what_to_search)
{
    int *last_element = a + a_size;

    while(0<a_size){
        if(*(--last_element) ==what_to_search)return 1;
        a_size--;
    }
    return -1;
}

int main()
{
    size_t a_size;
    int what_to_search;

    // printf("Enter the size of the array: ");
    scanf("%zu", &a_size);
    int a[a_size];

    // printf("Enter the elements of the array:\n");
    for (size_t i = 0; i < a_size; i++)
    {
        scanf("%d", &a[i]);
    }

    // printf("Enter the number to search for: ");
    scanf("%d", &what_to_search);

    int result = find_in_array(a, a_size, what_to_search);
    printf("%d", result);

    return 0;
}