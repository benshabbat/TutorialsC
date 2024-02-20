#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define the 2D array of strings
    char **strings;
    int rows = 3;

    // Allocate memory for the array of strings
    strings = malloc(rows * sizeof(char *));
    if (strings == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Input strings
    printf("Enter %d strings:\n", rows);
    for (int i = 0; i < rows; i++) {
        char *str;  // Assuming maximum string length is 99 characters
        printf("String %d: ", i + 1);
        if (scanf("%s", str) != 1) {
            fprintf(stderr, "Error reading input\n");
            exit(1);
        }
        strings[i] = malloc(strlen(str));
        if (strings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        strcpy(strings[i], str);
    }

    // Print the strings
    printf("Entered strings:\n");
    for (int i = 0; i < rows; i++) {
        printf("%s\n", strings[i]);
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}