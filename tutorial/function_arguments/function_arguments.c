
#include <stdio.h>

void birthday(char x[], int y)//<- parameters
{
   printf("\nHappy birthday dear %s!", x);
   printf("\nYou are %d years old!", y);
}

int main()
{
   char name[] = "David";
   int age = 30;

   birthday(name, age);//<-arguments

   return 0;
}