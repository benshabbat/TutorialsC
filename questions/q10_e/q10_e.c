/*
Write a function:  
void merge_sorted_arrays(int *a, size_t a_size, int *b, size_t b_size, int ** out_merged_array, size_t * output_size)  
 

Note: you can assume that a and b are sorted 

Note: the output array (out_merged_array) should be allocated inside the function – this is why it’s a double pointer, and, you should also set the output_size variable to be the size of this internally allocated array. 

Output should be without duplicates 

You should use only pointer arithmetic, not indexes such as a[i]. 

Usage example: 
int a[] = {1,2,3} 
int b[] = {2,4,6,8} 
int * c; size_t c_size; 
merge_sorted_arrays(a, 3, b, 4, &c, &c_size); 
// Output: c == {1,2,3,4,6,8} ; c_size == 6; 

 
 

*/


#include <stdio.h>
#include <stdlib.h>

void merge_sorted_arrays(int *a, size_t a_size, int *b, size_t b_size, int **out_merged_array, size_t *output_size){
    
}

int main() {
    size_t a_size, b_size;

    // printf("Enter the size of array a: ");
    scanf("%zu", &a_size);
    int a[a_size];
    
    // printf("Enter %zu elements for array a (sorted order):\n", a_size);
    for (size_t i = 0; i < a_size; i++) {
        scanf("%d", &a[i]);
    }

    //printf("Enter the size of array b: ");
    scanf("%zu", &b_size);
    int b[b_size];
    
    //printf("Enter %zu elements for array b (sorted order):\n", b_size);
    for (size_t i = 0; i < b_size; i++) {
        scanf("%d", &b[i]);
    }

    int *merged_array = NULL;
    size_t merged_size = 0;
    merge_sorted_arrays(a, a_size, b, b_size, &merged_array, &merged_size);

    printf("Merged array:\n");
    for (size_t i = 0; i < merged_size; i++) {
        printf("%d ", merged_array[i]);
    }
    
    printf("size: %d\n", merged_size);

    free(merged_array);
    return 0;
}