#include <stdio.h>
int func(int num, int digit)
{

    if (num < 0 || digit < 0 || num / 100 > 9 || digit > 9 || num / 10 < 10)
        return -1;
    int digit_num = num / 100;
    if (digit_num + (num % 10) == digit)
        return (digit_num * 10) + (num % 10);
    else if (digit_num + (num % 100 / 10) == digit)
        return (digit_num * 10) + (num % 100 / 10);
    else if ((num % 10) + (num % 100 / 10) == digit)
        return ((num % 10) * 10) + (num % 100 / 10);
    else
        return -1;
}

int main()
{
    int num = 0;
    num = func(430, 7);
    printf("%d\n", num);

    return 0;
}
