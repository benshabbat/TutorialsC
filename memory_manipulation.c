#include <stdio.h>
#include <string.h>

int main()
{
    int arr1[2] = {1, 2};
    int arr2[2] = {3, 4};

    // memset(arr1,1,sizeof(arr1));
    // printf("%d %d\n",arr1[0],arr1[1]);

    if (memchr(arr1, 2, sizeof(arr1)) != NULL)
    {
        printf("the number into arr1");
        printf(memchr(arr1, 2, sizeof(arr1)));
    }
    else
    {
        memchr(arr1, 3, sizeof(arr1));
        printf("the number dosent into arr1");
    }
}