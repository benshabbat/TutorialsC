#include <stdio.h>
#include <string.h>
#include <ctype.h>

int sum_digits_String(char *string)
{

  int sum = 0;
  int length = strlen(string);
  for (int i = 0; i < length; i++)
  {
    if (isdigit(string[i]))
    {
      sum += (string[i] - '0');
    }
  }
 
  return sum;
}

int main()
{
  char string[] = "aaa124a24";
  int sum = sum_digits_String(string);
  printf("sum: %d\n", sum);
  
  return 0;
}


