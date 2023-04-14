#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

int main() {
    ///
    int i, j, n;
    printf("enter n: ");
    scanf("%d", &n);

    double **matrix1 = (double **)malloc(n * sizeof(double *));
    double **matrix2 = (double **)malloc(n * sizeof(double *));
    for(i = 0; i < n; i++) {
        matrix1[i] = (double *)malloc(n * sizeof(double));
        matrix2[i] = (double *)malloc(n * sizeof(double));
    }

    printf("enter elenents:\n");
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("enter elenents of two matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    char op;
    printf("enter (+, -, *): ");
    scanf(" %c", &op);

    // Вычисление операции над матрицами
    double **result = matrix_operations(matrix1, matrix2, n, op);
    if(result == NULL) {
        return 1;
    }

    // Вывод результата
    printf("result:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    free_matrix(matrix1, n);
    free_matrix(matrix2, n);
    free_matrix(result, n);

    return 0;
}

