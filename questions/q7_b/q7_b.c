#include <stdio.h>

#define CALCULATE(x, y, operation) ((operation=='+')?x+y:(operation=='-')?x-y:(operation=='*')?x*y:(operation=='/')?x/y:0)

int main() {
    int x, y;
    char operation;
    printf("pls enter 2 num and operation(+,-,*,/) example 5 3 +\n");
    scanf("%d %d %c", &x, &y, &operation);

    printf("%d", CALCULATE(x, y, operation));
    return 0;
}