#include <stdio.h>
float swap(float *a, float *b){
    float temp=*a;
    *a=*b;
    *b=temp;
}

float mul_rec(float x, float y){
    if(x==0||y==0) return 0;
    if(y<0)swap(&x,&y);
    if(x<0&&y<0) {y*=-1; x*=-1;}
    return mul_rec(x,y-1)+x;
}

int main(){
    int num1=-5;
    int num2=-5;
    
    printf("%lf\n",mul_rec(num1,num2));
    return 0;
}