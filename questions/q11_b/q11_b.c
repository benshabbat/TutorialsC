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
        int length = strlen(str);
        char temp;

        for (int i = 0, j = length - 1; i < j; i++, j--)
        {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }