/*
Write a function: 
void concatinate_arrays(int *a, size_t a_size, int *b, size_t b_size, int ** out_merged_array, size_t * output_size)  

It should output a new array of size a_size + b_size, with the content of a and then the content of b.  

use memcpy! 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concatinate_arrays(int* a, size_t a_size, int* b, size_t b_size, int** out_merged_array, size_t* output_size) {
	// Allocate memory for the merged array
    *out_merged_array = (int *)malloc((a_size + b_size) * sizeof(int));
    if (*out_merged_array == NULL) {
        *output_size = 0;
        return;
    }

    // Copy array a into the merged array
    memcpy(*out_merged_array, a, a_size * sizeof(int));

    // Copy array b into the merged array after the content of a
    memcpy(*out_merged_array + a_size, b, b_size * sizeof(int));

    // Set the output size
    *output_size = a_size + b_size;
}

int main() {
    // Note: The following printf commands are commented out since they 
    //       confuse the auto testing of the output. However, you may find
    //       them useful for development needs. 
    //       Don't forget to comment out when you submit :)
    
	size_t a_size, b_size;
	//printf("Enter the size of array a: ");
	scanf("%zu", &a_size);
	int *a = (int*)calloc(sizeof(int), a_size);
	//printf("Enter %zu elements for array a:\n", a_size);
	for (size_t i = 0; i < a_size; i++) {
		scanf("%d", &a[i]);
	}

	//printf("Enter the size of array b: ");
	scanf("%zu", &b_size);
	int *b = (int*)calloc(sizeof(int), b_size);

	//printf("Enter %zu elements for array b:\n", b_size);
	for (size_t i = 0; i < b_size; i++) {
		scanf("%d", &b[i]);
	}

	int* merged_array = NULL;
	size_t merged_size = 0;
	concatinate_arrays(a, a_size, b, b_size, &merged_array, &merged_size);

	//printf("Concatenated array:\n");
	for (size_t i = 0; i < merged_size; i++) {
		printf("%d ", merged_array[i]);
	}
	//printf("\n");
	free(a);
	free(b);
	free(merged_array);
	return 0;
}