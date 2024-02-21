#include <stdio.h>
#include <stdlib.h>


void reverse_array(int * arr,int size){
    int* last_el = arr+size-1;
    int* first_el = arr;
    int temp=0;
    while(first_el < last_el){
        temp = *first_el;
        *first_el = *last_el;
        *last_el = temp;
        first_el++;
        last_el--;
    }
}
int main()
{

    int *arr;
    arr = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        *(arr + i) = i;
    }
    reverse_array(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d", *(arr + i));
    }
    free(arr);

    return 0;
}