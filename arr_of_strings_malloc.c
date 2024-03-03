#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char **strings;
    int total=0;

    printf("Enter a number total of Strings");
    scanf("%d", &total);
    strings = malloc(total*sizeof(char*));
    for(int i = 0; i < total; i++){
        strings[i] = strdup(strings[i]);
        
    }

    return 0;
}