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

void find_longest_common_substring(const char *str1, const char *str2, size_t *str1_substring_start_idx, size_t *str2_substring_start_idx, size_t *substring_length)
{

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    size_t **lcs = (size_t **)malloc((len1 + 1) * sizeof(size_t *));
    for (size_t i = 0; i <= len1; i++)
    {
        lcs[i] = (size_t *)malloc((len2 + 1) * sizeof(size_t));
    }

    size_t max_length = 0;
    size_t end_position = 0;

    for (size_t i = 0; i <= len1; i++)
    {
        for (size_t j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0)
            {
                lcs[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                if (lcs[i][j] > max_length)
                {
                    max_length = lcs[i][j];
                    end_position = i - 1;
                }
            }
            else
            {
                lcs[i][j] = 0;
            }
        }
    }

    *substring_length = max_length;
    *str1_substring_start_idx = end_position - max_length + 1;
    *str2_substring_start_idx = end_position - max_length + 1;
    for (size_t i = 0; i <= len1; i++)
    {
        free(lcs[i]);
    }
    free(lcs);
}
