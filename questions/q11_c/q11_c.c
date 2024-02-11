/*
Implementing yourself (something similar to) strcmp function!
Write a function
bool my_strcmp(char * str1, char * str2);
that receives two strings and returns true if they’re identical, or otherwise false.
Important: You can’t use any functions from string.h
*/



#include <stdbool.h>
#include <stdlib.h>

bool my_strcmp(char *str1, char *str2) {

    while(*str1!='\0'&&*str2!='\0') {
        if(*str1!=*str2){
            return false;
        }
        else{
            str1++;
            str2++;
        }
    }

    if(*str1!='\0'||*str2!='\0'){
        return false;
    }

   return true;
}