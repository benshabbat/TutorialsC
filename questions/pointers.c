#include <stdio.h>
#include <stdlib.h>
int main()
{
    // int x = 5;
    // int* p_x = &x;
    // int** p_p_x = &p_x;
    // // p_x+=1;
    // printf("pointer %p p_p %p",p_x,p_p_x );

    // ex 2
    // int x[5];

    // //*(x+1) == x[1];
    // x[1] = 56;
    // *(x + 1) = 44;

    // printf("*(x+1) %d", x[1]);

    // ex 3
    // int x[5];

    //*(x+1) == x[1];
    // x[1] = 56;
    // *(x + 1) = 44;
    //&(*(x+1))==&X[1]
    // printf("Enter a number");
    // scanf("%d", &(*(x+1)));
    // printf("*(x+1) %d", x[1]);

    // ex4
    //  int num =0;
    //  printf("Enter a number ");
    //  scanf("%d", &num);
    //  int* nums = (int*)malloc(num * sizeof(int));

    // for(int i=0; i<num; i++){
    //     printf("Enter a numbers ");
    //     scanf("%d", nums+i);  // nums+i ==> &nums[i];
    // }
    // for(int i=0; i<num; i++){
    //     printf("%d\n", *(nums+i)); // *(nums+i)) ==> nums[i];
    // }
    // free(nums);

    // ex5
    int rows, cols;

    // Ask the user for the dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Read values into the matrix from the user
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}