#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Needed for malloc and free

int main() {
    char *src = "Hello, world!";
    char *dest = malloc(strlen(src) + 1); // Allocate memory for dest

    // Check if memory allocation was successful
    if (dest == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Using memcpy to copy src to dest
    memcpy(dest, src, strlen(src) + 1); // Copy the null terminator too

    // Print the copied string
    printf("Copied string: %s\n", dest);

    // Free the allocated memory
    free(dest);

    return 0;
}