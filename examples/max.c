#include <stdio.h>

int main(void){
    int myArr[]= {55,8,22,77,11,55,33,66,99,1233,321,44,7,444};
    int max=myArr[0];
    for(int i=1;i<=sizeof(myArr)/sizeof(myArr[0])-1;i++)
    {
        if(myArr[i]>max){
            max=myArr[i];
        }
    }
    printf("%d\n",max);
    return 0;
}