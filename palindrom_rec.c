#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

char *substring(char *str, int a, int b)
{
    char *str2 = malloc(b - a + 1); // Allocate memory for the substring
    strncpy(str2, str + a, b - a);  // Copy the substring
    str2[b - a] = '\0';             // Null-terminate the string
    return str2;
}

bool isPalindrome_rec(char *str)
{
    int len = strlen(str);
    if (len <= 1)
        return true;

    if (str[0] != str[len - 1])
        return false;
    
    // Allocate memory for the substring
    char *sub = substring(str, 1, len - 1);

    // Check if the substring is a palindrome
    bool result = isPalindrome_rec(sub);

    // Free the allocated memory
    free(sub);

    return result;
}

int main()
{
    char str[] = "aaAaAaa";
    if (isPalindrome_rec(str))
        printf("'%s' is a palindrome.\n", str);
    else
        printf("'%s' is not a palindrome.\n", str);

    return 0;
}