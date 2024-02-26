#include "Question.h"

void sortArr(int arr[], int size, int iterations) {
    int temp =0;
    for(int i = 0 ; i < size && iterations ; ++i, iterations--) {
        for(int j = i; j > 0 ; --j) {
            // complete insertion sort implementation here:
             if(arr[j] < arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else{
                break;
            }
            // START
            // END
        }
    }
}