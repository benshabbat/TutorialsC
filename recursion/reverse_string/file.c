#include <string.h>
#include <stdio.h>


void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_string(char *s1, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    swap(&s1[start], &s1[end]);

    return reverse_string(s1, start + 1, end - 1);
}

int main()
{   

    char str[] = "Hello, World!";
    int length = strlen(str);

    // Reverse the string
    reverse_string(str, 0, length - 1);

    printf("Reversed string: %s\n", str);
    return 0;
}