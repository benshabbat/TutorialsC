#include <stdio.h>
#include <string.h>

int main() {    //12345678901234567890
    char str[] = "hello";
    memmove(str+2,str,2);
    printf("%s\n", str);
    return 0;
}