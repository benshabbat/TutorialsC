/*
Write a function:
void reverse_array(int * array_first_element, int * array_last_element, size_t size);
That receives pointers to the first and last elements of an array and reverses the order of its elements.
*/

#include <stdio.h>

void reverse_array(int *array_first_element, int *array_last_element, size_t size) {
    
     for (int i = size-1; i >= 0; i--) {
        array_last_element =array_first_element+i;
        printf("%d ", *array_last_element);
    }
}

int main() {
    int arr_size, i;

    // Note: The following printf commands are commented out since they 
    //       confuse the auto testing of the output. However, you may find
    //       them useful for development needs. 
    //       Don't forget to comment out when you submit :)
    
    //printf("Enter the size of the array: ");
    scanf("%d", &arr_size);

    int arr[arr_size];

    //printf("Enter %d elements of the array:\n", arr_size);
    for (i = 0; i < arr_size; i++) {
        scanf("%d", &arr[i]);
    }

    reverse_array(arr, arr + arr_size - 1, arr_size);

    printf("Reversed array:\n");
    for (i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
