#include <stdio.h>

void rotate_right_once(int arr[], int len)
{
    int temp = arr[len - 1];
    for (int i = len-1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}

void rotate_right(int arr[],int len, int num){
    
    for(int i = 0; i < num%len; i++){
        rotate_right_once(arr,len);
    }
}
int main()
{
    int arr[] = {1, 2, 5, 6, 7, 9, 11};
    int len = sizeof(arr) / sizeof(arr[0]);
    rotate_right(arr,len,5);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}