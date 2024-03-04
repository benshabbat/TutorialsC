#include <stdio.h>

int sum_rec(int n)
{
    if(n==0) return n;
    return n%10+sum_rec(n/=10);
}

int main()
{
    int x = 3325;
    x = sum_rec(x);
    printf("%d\n",x);
    return 0;
}