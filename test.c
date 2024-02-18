#include <stdio.h>


int main(){

    int matrix[3][5]=
    {
        {0,1,2,3,4},
        {5,6,7,8,9},
        {10,11,12,13,14}
    };
    printf("%d\n",matrix);
    printf("%d\n",matrix[0]);
    printf("%d\n",*(*(matrix+2)+2));//matrix[1][3];
    printf("%d\n",matrix[2][2]);//;
    

    return 0;
}