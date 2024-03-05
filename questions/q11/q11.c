#include "Question.h"
#include <stdio.h>
#include <string.h>

void find_longest_common_substring(
    const char* str1,
    const char* str2,
    size_t* str1_substring_start_idx,
    size_t* str2_substring_start_idx,
    size_t* substring_length) {
        
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    size_t **dp = malloc((len1 + 1) * sizeof(size_t *));
    for (size_t i = 0; i <= len1; ++i) {
        dp[i] = malloc((len2 + 1) * sizeof(size_t));
        memset(dp[i], 0, (len2 + 1) * sizeof(size_t));
    }

    size_t max_length = 0;
    *str1_substring_start_idx = 0;
    *str2_substring_start_idx = 0;

    for (size_t i = 1; i <= len1; ++i) {
        for (size_t j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max_length) {
                    max_length = dp[i][j];
                    *str1_substring_start_idx = i - max_length;
                    *str2_substring_start_idx = j - max_length;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    *substring_length = max_length;

    for (size_t i = 0; i <= len1; ++i) {
        free(dp[i]);
    }
    free(dp);
}