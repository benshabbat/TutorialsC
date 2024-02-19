#include <stdio.h>
#include <string.h>

int main() {
    char *src = "Hello, world!";
    char *dest;

    // Using memcpy to copy src to dest
    memcpy(dest, src, strlen(src));

    // Print the copied string
    printf("Copied string: %s\n", dest);

    return 0;
}