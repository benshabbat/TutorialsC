/*
Write a C program that transposes a 3x3 matrix.
Explanation:
"matrix" in mathematics = 2d array in programming
transpose = turn the rows into columns and vice versa.
for example:
The transpose of
A=1 2 3
  4 5 6
  7 8 9

is

A=1 4 7
  2 5 8
  3 6 9




Read nine numbers from the user (row-wise) to form a 3x3 matrix.
Compute the transpose of the matrix.
Print the transposed matrix.
*/

#include <stdio.h>


int main()
{
    int n = 3;
    int arr[n][n];
    // insert matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter a number for [%d][%d]", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // print matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
printf("*********after rotate*******************\n");
    // rotate matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[j][i]);//changed just row and col
        }
        printf("\n");
    }

    return 0;
}