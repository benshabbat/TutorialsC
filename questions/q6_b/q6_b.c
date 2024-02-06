/*
Write a program in C that reads 10 numbers (stores them in an array) and then prints the second smallest value in an array.
If there is no second smallest (all elements have the same value) print "N/A"
*/

#include <stdio.h>

void find_second_min(int *my_arr, int length)
{
    int min = my_arr[0];
    int second_min = my_arr[0];
    for (int i = 1; i <= length - 1; i++)
    {
        if (my_arr[i] < min)
        {
            second_min = min; // the min will second min
            min = my_arr[i];
        }
        // maybe the num from arr bigger than min but smaller than second min
        else if (my_arr[i] < second_min && my_arr[i] != min)
            second_min = my_arr[i];
    }
    if (min < second_min)
        printf("%d", second_min); // if the second smallest not equal to the first smallest
    else
        printf("N/A");
}

int main()
{

    int length = 10;
    int array[length];
    // int size = sizeof(array) / sizeof(array[0]);

    // insert data
    for (int i = 0; i < length; i++)
    {
        printf("Enter the number %d# \n", i + 1);
        scanf("%d", &array[i]);
    }
    find_second_min(array, length);
    return 0;
}