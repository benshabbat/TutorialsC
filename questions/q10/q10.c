/*
Write a function:
void multiply_by_2(int * a)
That changes the value pointed by "a" to be twice as big
*/

#include <stdio.h>

void multiply_by_2(int *a) {
    *a *=2;
}

int main() {
    int num;
    scanf("%d", &num);
    multiply_by_2(&num);
    printf("%d", num);
    return 0;
}