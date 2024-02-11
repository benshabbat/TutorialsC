/*
This time, you’ll Implement the strrev function!

Write a function

void my_strrev(char * str);

that reverts in place the string that it gets.
“in place” means that you should change the values of the input array,
not allocate a new string for holding the result.

Important instructions!
1. You can’t use any functions from string.h

2. Hint: a simple trick to find the end of a string:

char * end_of_string_ptr = str;
for ( ; *end_of_string_ptr ; end_of_string_ptr++) {}

Use it only if you understand it 😉
*/

#include "Question.h"
#include <stdio.h>

void my_strrev(char *str)
{

#include "Question.h"
#include <stdio.h>

    void my_strrev(char *str)
    {
        // Find the length of the string 
        int length = 0;
        while (str[length] != '\0')
        {
            length++;
        }

        // Reverse the string
        char temp;
        for (int i = 0; i < length / 2; i++)
        {
            temp = str[i];
            str[i] = str[length - i - 1];
            str[length - i - 1] = temp;
        }
    }