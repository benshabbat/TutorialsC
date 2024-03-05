#include <string.h>
#include <stdio.h>
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
char *reverse_string_rec(char *string, int len)
{
    if (len <= 0)
        return string; // Base case: return the original string
    swap(string, string + len - 1);
    //hello //oellh
    //ell //lle
    //l //l
    //len = -1 return the string

    return reverse_string_rec(string + 1, len - 2); // Recursive call
}

int main()
{
    char str[] = "Hello"; // Declare as array, not pointer
    reverse_string_rec(str, strlen(str));
    printf("%s\n", str);
    return 0;
}