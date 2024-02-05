/*

Write a C program that:
1. reads three integer values from the input: a,b, and c.
2. it prints :  ((a+1) + (1+b)) modulus c
without using the digit "1" in the code.

*/

#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;

    do
    {
        // the variables with digit 1
        if (a == 1)
            printf("the number a cannot be a 1 digit\n");
        if (b == 1)
            printf("the number b cannot be a 1 digit\n");
        if (c == 1)
            printf("the number c cannot be a 1 digit\n");
        printf("puts number without num 1\n");

        if (a == 1 || a == 0)// if to back for reset value
        {
            printf("Enter a number:\n");
            scanf("%d", &a);
            if (a == 1)
                continue; // stop to put more digits
        }
        if (b == 1 || b == 0)// if to back for reset value
        {
            printf("Enter b number:\n");
            scanf("%d", &b);
            if (b == 1)
                continue; // stop to put more digits
        }
        if (c == 1 || c == 0)// if to back for reset value
        {
            printf("Enter c number:\n");
            scanf("%d", &c);
            if (c == 1)
                continue; // stop to put more digits
        }
    } while (a == 1 || b == 1 || c == 1);

    printf("the res is :%d\n", ((a + 1) + (1 + b)) % c);
    return 0;
}