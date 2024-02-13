#include "Question.h"

// Function definition - students are required to complete this function
uint32_t reverseBits(uint32_t n)
{

    uint32_t reversed = 0;
    int bitPosition = 31;
    while (n)
    {
        reversed |= (n & 1) << bitPosition;
        n >>= 1;
        bitPosition--;
    }

    // TODO: Implement the function to reverse the bits of 'n'
    return reversed; // Placeholder return, to be replaced by actual implementation
}