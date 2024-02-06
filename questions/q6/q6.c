/*
Write a program in C that reads 10 numbers and stores them into an array,
then displays them in reverse order
*/

#include <stdio.h>
void reverse_sort(int array[], int size)
{
   for(int i = 0; i < size - 1; i++)
   {
      for(int j = 0; j < size - i - 1; j++)
      {
         if(array[j] < array[j+1])
         {
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
         }
      }
   }
}

void print_array(int array[], int size)
{
   for(int i = 0; i < size; i++)
   {
      printf("%d ", array[i]);
   }
}
int main()
{
    int size = 10;
    int array[size];
    // int size = sizeof(array) / sizeof(array[0]);

    //insert data
    for(int i = 0; i < size; i++){
        printf("Enter the number %d# \n", i+1);
        scanf("%d", &array[i]);
    }
    reverse_sort(array, size);
    print_array(array, size);
    return 0;
}