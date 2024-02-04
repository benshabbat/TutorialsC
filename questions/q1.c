#include <stdio.h>

//Write a C program that reads three values of whole numbers 
//(which can be negative) into variables x, y, and z, and prints the distance between x + y to z

int main()
{
    int x,y,z;

    printf("Enter Number1#: \n");
    scanf("%d",&x);
    printf("Enter Number2#: \n");
    scanf("%d",&y);
    printf("Enter Number3#: \n");
    scanf("%d",&z);
    // if the num is negative i using *-1
    printf("The distance between the two numbers(x and y) to the third number(z):%d",(x+y)-z<0?((x+y)-z)*-1:(x+y)-z); 

    return 0;
}