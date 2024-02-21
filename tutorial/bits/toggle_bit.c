#include <stdio.h>
#include <stdint.h>
void printbits(int input)
{
    int i, mask;

    for (i = 31; i >= 0; i--)
    {
        mask = 1 << i;
        if (input & mask)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}
int main()
{

    uint8_t num = 0b00011010; // 26 in binary
    int pos = 2;              // position to toggle
    num ^= (1 << pos);        // toggle the bit at position 2
                              // num is now 0b00011110 (30 in decimal)
    printbits(num);           // print
                             
    return 0;
}
