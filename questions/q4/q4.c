/*
Scan an integer number from the user,
print "true" if it's a prime number, otherwise print "false"
*/

#include <stdio.h>

int main()
{
    int number =0;
    printf("Enter a number: \n");
    scanf("%d", &number);
    if(number ==2)printf("true\n");
    for(int i=2; i<number; i++){
        if(number %i == 0){
            printf("false");
            break;
        }
        if(number==i+1){
            printf("true");
        }
    }
    return 0;
}