#include <stdio.h>
#include <stdbool.h>

bool res(int *arr, int len,int k){
    if(len==-1&&k>0) return false;
    if(k==0)return true;
    if(k<0)k+=arr[len];
    return res(arr,len-1,k-arr[len-1]);
}
int main(){
    int arr[]={4,5,6};
    int k=11;
    if(res(arr,sizeof(arr)/sizeof(arr[0]),k))
        printf("True");
    else 
        printf("False");
    return 0;
}