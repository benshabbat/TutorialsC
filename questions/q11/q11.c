/*
In this exercise, you will implement a function that finds the common substring between two strings:

// Input: str1, str2
// Output:
// 1. str1_substring_start_idx,
// 2. str2_substring_start_idx,
// 3. substring_length
void find_longest_common_substring(
const char * str1, const char * str2,
size_t * str1_substring_start_idx,
size_t * str2_substring_start_idx,
size_t * substring_length)

For example, for the following input:
Index: 012345678901234567890123456789012345678901234567890123456789012345678
Str1 = “we are learning c language we are practicing the string library today”
Str2 = “we love practicing the string library functions in c language”
will identify the common longest substring (highlighted) and set the output parameters to:
str1_substring_start_idx = 6
str2_substring_start_idx = 32
substring_length = 32
*/

#include "Question.h"
#include <stdio.h>
#include <string.h>

void find_longest_common_substring(
    const char *str1,
    const char *str2,
    size_t *str1_substring_start_idx,
    size_t *str2_substring_start_idx,
    size_t *substring_length)
{

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int count = 0;
    int biggest = 0;
    int start_i = 0;
    int start_j = 0;

    if (len1 > len2)
    {           //ASSASSAFFFDS
                //adssaSSAFF
        for (int i = 0; i < len1; i++)
        {
            for (int j = 0; j < len2; j++)
            {
                if (str1[i] == str2[j])
                {
                    str1_substring_start_idx = i;
                    str2_substring_start_idx = j;
                    count++;
                    i++;
                    j++;
                    if (count > biggest)
                    {
                        biggest = count;
                        start_i = i - count;
                        start_j = j - count;
                    }
                }
                else
                {
                    count = 0;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < len2; i++)
        {
            for (int j = 0; j < len1; j++)
            {
                if (str1[i] == str2[j])
                {

                    substring_length = count;
                    str1_substring_start_idx = i;
                    str2_substring_start_idx = j;
                    count++;
                    i++;
                    j++;
                    if (count > biggest)
                    {
                        biggest = count;
                        start_i = i - count;
                        start_j = j - count;
                    }
                }
                else
                {
                    count = 0;
                }
            }
        }
    }
    str1_substring_start_idx=start_i;
    str2_substring_start_idx=start_j;
    substring_length=biggest;
}