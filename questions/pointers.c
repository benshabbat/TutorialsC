#include <stdio.h>
int main()
{
    // int x = 5;
    // int* p_x = &x;
    // int** p_p_x = &p_x;
    // // p_x+=1;
    // printf("pointer %p p_p %p",p_x,p_p_x );

    // ex 2
    // int x[5];

    // //*(x+1) == x[1];
    // x[1] = 56;
    // *(x + 1) = 44;

    // printf("*(x+1) %d", x[1]);

    // ex 3
    int x[5];

    //*(x+1) == x[1];
    // x[1] = 56;
    // *(x + 1) = 44;
    //&(*(x+1))==&X[1]
    printf("Enter a number");
    scanf("%d", &(*(x+1)));
    printf("*(x+1) %d", x[1]);

    return 0;
}