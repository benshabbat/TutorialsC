
#include <stdio.h>
#include <string.h>

int main(){

    char name[25]; //bytes
    int age;

    printf("\nWhat's your name?\n");
    //scanf("%s", &name);
    fgets(name, 25, stdin);
    name[strlen(name)-1] = '\0';

    printf("How old are you?\n");
    scanf("%d", &age);

    printf("\nHello %s", name);
    printf("\nYou are %d years old", age);

    return 0;
}