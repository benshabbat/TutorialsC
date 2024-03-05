#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(){

    char **strings;
    int total=0;

    printf("Enter a number total of Strings\n");
    scanf("%d", &total);
    strings = malloc(total*sizeof(char*));

    char *string;
    char buffer[BUFFER_SIZE];
    int length = 0;

    while(getchar() !='\n');

    for(int i = 0; i < total; i++){
        printf("Enter a string %d\n", i+1);
        fgets(buffer, BUFFER_SIZE,stdin);
        length = strlen(buffer);
        //why len-1 bc fgets gets the enter
        buffer[length-1] = '\0';
        strings[i] = malloc(length*sizeof(char));
        // strcpy(strings[i],buffer);
        strings[i]=strdup(buffer);
    }
    printf("\n");
    for(int i = 0; i < total; i++){
        printf("%s\n", strings[i]);
        // free(strings[i]);
    }
    for(int i = 0; i < total; i++){
        // printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);
    return 0;
}