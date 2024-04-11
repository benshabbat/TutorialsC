#include <stdio.h>


int summation(int num){
    if(num<=1)return num;
    return num+summation(num-1);
}

int main()
{
    printf("summation = %d\n",summation(10));
    return 0;
}