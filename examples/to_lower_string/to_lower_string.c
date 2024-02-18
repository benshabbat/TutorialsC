#include <string.h>
#include <stdio.h>
#include <ctype.h>

void tolower_str(char *s) {
    while (*s) {
        if(*s == isupper(*s)) s++;
        *s = tolower(*s);
        s++;
    }
}


int main(){
    // char *s = "helloDA woAASDSArld";//String literals are typically stored in read-only memory
    char s[] = "helloDA woAASDSArld";
    printf("%s\n", s);
    tolower_str(s);
    printf("%s\n", s);
    return 0;
}