#include <stdio.h>

void decimalToBinary(int n, char *buffer, int *index) {
    if (n == 0) {
        return;
    }

    decimalToBinary(n / 2, buffer, index);
    buffer[(*index)++] = (n % 2) + '0';
}

int main() {
    int decimal;
    char buffer[32]; // Assuming 32-bit integers
    int index = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal, buffer, &index);
    buffer[index] = '\0';

    printf("Binary equivalent: %s\n", buffer);

    return 0;
}