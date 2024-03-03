#include <stdio.h>
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}
int main()
{
    int x =5;
    x=factorial(x);
    printf("x = %d\n",x);
    return 0;
}