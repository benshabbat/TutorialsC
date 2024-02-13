#include <stdio.h>

int hammingWeight(uint32_t n)
{
    // TODO: Implement the function to count and return the number of '1' bits in 'n'
    int count = 0;
    while (n)
    {
        
        count += n & 1;
        printf("%d", n & 1);
        printf("%d", count);
        n >>= 1;
    }
    return count; // Placeholder return, to be replaced by actual implementation
}
int main()
{
    uint32_t n = 1011110111110;
    n = hammingWeight(n);
    printf("%d\n", n);
    return 0;
}