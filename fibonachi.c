#include <stdio.h>

int fib_recursion(int n)
{
    if (n > 1)
        return fib_recursion(n - 1) + fib_recursion(n - 2);
    else if (n == 1 || n == 0)
        return n;
    else
        return -1;
}
void fib(int n)
{
    int num1 = 0;
    int num2 = 1;
    int temp;
    if (n > 2)
    {
        printf("%d,%d,", num1, num2);
        for (int i = 2; i < n; i++)
        {
            temp = num1;
            num1 = num2;
            num2 += temp;
            if (i != n - 1)
            {
                printf("%d,", num2);
            }
            else
                printf("%d", num2);
        }
    }
}

int main()
{

    int length = 10;
    int x;
    printf("Recursion\n");
    for (int i = 0; i < length; i++)
    {
        x = fib_recursion(i);
        if (i != length - 1)
        {
            printf("%d,", x);
        }
        else
            printf("%d", x);
    }
    printf("\n");
    printf("normal\n");
    fib(10);
    return 0;
}