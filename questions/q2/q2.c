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
        if(a==1)printf("the number a cannot be a 1 digit\n");
        printf("Enter a number:\n");
        scanf("%d", &a);
        if(b==1)printf("the number b cannot be a 1 digit\n");
        printf("Enter b number:\n");
        scanf("%d", &b);
        if(c==1)printf("the number c cannot be a 1 digit\n");
        printf("Enter c number:\n");
        scanf("%d", &c);
    } while (a == 1 || b == 1 || c == 1);

    printf("the res is :%d\n",((a+1) + (1+b)) % c);
    return 0;
}