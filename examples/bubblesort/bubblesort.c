#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int arr[], int len)
{
    int check=0;
    for (int j = 0; j < len; j++)
    {

        for (int i = 0; i < len-1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr+i, arr+(i+1));
                check++;
            }
        }
        if(check == 0)break;
        else check=0;
    }
}

int main()
{
    int arr[] = {5, 8, 36, 42, 6, 8, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d,", arr[i]);
    }
    return 0;
}