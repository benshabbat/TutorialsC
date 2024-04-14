#include <stdio.h>


int fib(int num){
    if(num==0||num==1) return num;
    else return fib(num-1)+fib(num-2);
}


int main(){
    printf("%d",fib(10));
}