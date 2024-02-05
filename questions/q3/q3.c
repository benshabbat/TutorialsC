/*
Your program should scan an integer number from the user,
this number is a mark between 0 and 100 .

Then, it should output the appropriate mark category by the following table:

100 <-> 90	89 <-> 75	74<-> 50	49<->35	34<-> 0
A	B	C	D	F


If the mark is not in the range, print X
*/

#include <stdio.h>
int main()
{
    int number = 0;
    printf("Enter a Number between 0-100: \n");
    scanf("%d", &number);

    if (number <= 100 && number >= 90)
        printf("A");
    else if (number <= 89 && number >= 75)
        printf("B");
    else if (number <= 74 && number >= 50)
        printf("C");
    else if (number <= 49 && number >= 35)
        printf("D");
    else if (number <= 34 && number >= 0)
        printf("F");
    else
        printf("X");

    return 0;
}