#include <stdio.h>

// Function definition - students are required to complete this function
int reverseBits(int n)
{

    int reversed = 0;
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
void printbits(int input){
    int i, mask;

    for(i=31; i >= 0; i--){
       mask = 1 << i;
       if(input & mask){
          printf("1");
       }else{
          printf("0");
       }
    }
 }

int main()
{
    int num = 1;
    num = reverseBits(num);
    printbits(num);
    // printf("%08x\n", num);
    return 0;
}