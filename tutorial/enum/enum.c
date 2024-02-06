#include <stdio.h>

enum Day{Rishon = 1, Sheni = 2, Shlishi = 3, Revii = 4, Hamishi = 5, Shishi = 6, Shabbat = 7};

int main()
{
   // enum = a user defined type of named integer identifiers
   //               helps to make a program more readable

   enum Day today;
   today =  Shishi;

   if(today == Shishi || today == Shabbat)
   {
      printf("\nthe Shabbat is ready!");
   }
   else
   {
      printf("\nI have to work today :(");
   }
 
   return 0;
}