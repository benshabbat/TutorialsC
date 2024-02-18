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
    int pos = 4;              // position to clear
    num &= ~(1 << pos);       // clear the bit at position 4
    printbits(num);           // print
                              // num is now 0b00001010 (10 in decimal)
    return 0;
}
