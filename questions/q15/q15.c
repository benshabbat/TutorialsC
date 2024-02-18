#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main()
{
    uint32_t n = 011101100111U; // Note the U suffix for uint32_t constant
    n = hammingWeight(n);
    printf("%u\n", n);
    return 0;
}