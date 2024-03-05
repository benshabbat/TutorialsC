#include <stdio.h>

void rotate_left_once(int arr[], int len)
{
    int temp = arr[0];
    for (int i = 0; i <len; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[len-1] = temp;
}

void rotate_left(int arr[],int len, int num){
    
    for(int i = 0; i < num%len; i++){
        rotate_left_once(arr,len);
    }
}
int main()
{
    int arr[] = {1, 2, 5, 6, 7, 9, 11};
    int len = sizeof(arr) / sizeof(arr[0]);
    rotate_left(arr,len,5);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}