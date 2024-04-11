#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool palindrom(char *s1, int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    if (s1[start] != s1[end])
    {
        return false;
    }

    return palindrom(s1, start + 1, end - 1);
}

int main()
{

    char str[] = "aSDsDSa";
    int length = strlen(str);

    // Reverse the string
    if (palindrom(str, 0, length - 1))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}