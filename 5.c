#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

int main() {
    int n, i;
    printf("enter size of matrix: ");
    scanf("%d", &n);
    double **matrix1 = newMatrix(n);
    double **matrix2 = newMatrix(n);
    printf("enter elements first matrix :\n");
    fillMatrix(matrix1, n);
    printf("enter elements second matrix:\n");
    fillMatrix(matrix2, n);
    printf("enter action (+, -, *): ");
    char operation;
    scanf(" %c", &operation);
    
    double **result;
    switch (operation) 
	{
        case '+':
            result = plusMatrix(matrix1, matrix2, n);
            break;
        case '-':
            result = minusMatrix(matrix1, matrix2, n);
            break;
        case '*':
            result = xMatrix(matrix1, matrix2, n);
            break;
        default:
            printf("error\n");
            return 1;
    }

    printf("new matrix:\n");
    
    printMatrix(result, n);
    
    //ќсвобождаем пам€ть, использованную при работе
    for (i = 0; i < n; i++)
	{
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
