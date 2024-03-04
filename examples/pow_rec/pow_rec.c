#include <stdio.h>

float pow_rec(float x, int n)
{
    if (n == 1)
        return x;
    else if(n<0)
    {
        n*=-1;
        x=1/x;
    }
    else if(n==0)return 1;
    return pow_rec(x, n - 1) * x;
}
int main()
{
    printf("%lf\n", pow_rec(2, -2));
    return 0;
}