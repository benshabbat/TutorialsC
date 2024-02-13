#include "Question.h"

// Function to check if 'n' is a power of two
bool isPowerOfTwo(int n)
{
    // TODO: Implement the function to check if 'n' is a power of two
    if (n <= 0)
    {
        return false;
    }
    return (n & (n - 1)) == 0; // Placeholder return, to be replaced by actual implementation
}