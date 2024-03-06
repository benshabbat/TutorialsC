#include <stdio.h>

float pow(float base, float power){
    if(power==0)return 1;
    else if(power==1)return base;
    else if(power<0) return (base,power+1)*1/base; 
    return (base,power-1)*base; 
}

int main(){
    float base =2.3;
    float power = 2.1;
    printf("%lf", pow(base, power));
    return 0;
}