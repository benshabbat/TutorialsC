#include <stdio.h>
int main()
{
    int x = 5;
    int* p_x = &x;
    int** p_p_x = &p_x;
    // p_x+=1;
    printf("pointer %p p_p %p",p_x,p_p_x );
    return 0;
}