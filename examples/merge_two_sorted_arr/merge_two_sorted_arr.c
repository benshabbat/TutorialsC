#include <stdio.h>

void merge(int arr1[], int len_arr1, int arr2[], int len_arr2, int arr3[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < len_arr1 && j < len_arr2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
            arr3[k++] = arr2[j++];
    }
    while (i < len_arr1)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < len_arr2)
    {
        arr3[k++] = arr2[j++];
    }
}

int main()
{
    int a[] = {1, 2, 4, 5, 6, 8};
    int b[] = {4, 7, 9, 10, 12, 18};
    int len_a = sizeof(a) / sizeof(a[0]);
    int len_b = sizeof(b) / sizeof(b[0]);
    int c[len_a + len_b];
    merge(a, len_a, b, len_b, c);
    for (int i = 0; i < len_a + len_b; i++)
    {
        if (len_a + len_b-1 > i)
            printf("%d,", c[i]);
        else
            printf("%d", c[i]);
    }

    return 0;
}