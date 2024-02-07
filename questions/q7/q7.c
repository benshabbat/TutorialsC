/*
Write a macro #define SQUARE(x) that calculates the square of a number x.
*/

#include <stdio.h>

#define SQUARE(num) num*num

int main() {
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    printf("%d", SQUARE(x));
    return 0;
}