#include <stdio.h>

int binary_search(int *arr, int left, int right,int x){
    if(left>=right){
        return -1;
    }

    int mid= (left+right)/2;

    if(arr[mid]==x){
        return mid;
    }
    if(arr[mid]>x)return binary_search(arr,left,mid-1,x);
    if(arr[mid]<x)return binary_search(arr,mid+1,right,x);
}


int main(){
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = binary_search(arr, 0, n - 1, key);
    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}
