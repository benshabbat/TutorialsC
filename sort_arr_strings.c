#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap_strings(char **s1, char **s2)
{
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void sort_strings(char **str, int len)
{
    for (int i = 0; i < len; i++)
    {
        int index_min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (strcmp(str[j], str[index_min]) < 0)
            {
                index_min = j;
            }
        }
        swap_strings(&str[i], &str[index_min]);
    }
}

int main()
{
    char *strings[10] = {
        "hello",
        "this",
        "is",
        "array",
        "of",
        "strings",
        "for",
        "example",
        "sort",
        ":)"};
    int len = 10;
    sort_strings(strings, len);
    for (int i = 0; i < len; i++)
    {
        printf("%s ", strings[i]);
    }
    return 0;
}