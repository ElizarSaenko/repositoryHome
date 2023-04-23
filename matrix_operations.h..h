// ����: matrix_operations.c

#include <stdio.h>
#include <stdlib.h>

// ������� ��� ������������ ������
int i, n;
void free_matrix(double **matrix, n) {
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// ������� ��� ���������� �������� ��� ���������
double **matrix_operation(double **matrix1, double **matrix2, int n, char op) {
	int i, j, k;
    double **result = (double **)malloc(n * sizeof(double *));
    for(i = 0; i < n; i++) {
        result[i] = (double *)malloc(n * sizeof(double));
    }

    switch(op) {
        case '+': // �������� ������
            for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            break;
        case '-': // ��������� ������
            for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            break;
        case '*': // ��������� ������
            for(i = 0; i < n; i++) {
                for(j = 0; j < n; j++) {
                    double sum = 0;
                    for(k = 0; k < n; k++) {
                        sum += matrix1[i][k] * matrix2[k][j];
                    }
                    result[i][j] = sum;
                }
            }
            break;
        default:
            fprintf(stderr, "�������� ���� ��������!\n");
            return NULL;
    }

    return result;
}
