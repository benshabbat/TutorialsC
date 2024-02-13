#include "Question.h"

// Function definition - students are required to complete this function
uint32_t reverseBits(uint32_t n) {

    while (n)
    {
        
        count += n & 1;
        printf("%d", n & 1);
        printf("%d", count);
        n >>= 1;
    }
    // TODO: Implement the function to reverse the bits of 'n'
    return 0;  // Placeholder return, to be replaced by actual implementation
}