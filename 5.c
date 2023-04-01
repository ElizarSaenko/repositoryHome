#include <stdio.h>
#include <stdlib.h>

// ���������� �������, ������� ����� ��������� �������� � ���������
double* performOperation(double* matrix1, double* matrix2, int n, char operation);

int main() {
    int n, i, j;
    char operation;
    double* matrix1;
    double* matrix2;
    double* result;

    // ������ ����������� ������
    printf("Enter the dimension of the matrices (N): ");
    scanf("%d", &n);

    // ������������ ��������� ������
    matrix1 = (double*)malloc(n * n * sizeof(double));
    matrix2 = (double*)malloc(n * n * sizeof(double));

    // ������ ��������� ������ �������
    printf("Enter the elements of the first matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i * n + j]);
        }
    }

    // ������ ��������� ������ �������
    printf("Enter the elements of the second matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &matrix2[i * n + j]);
        }
    }

    // ������ ��������
    printf("Enter the operation (+, -, or *): ");
    scanf(" %c", &operation);

    // ����� �������, ������� ��������� �������� � ���������� ���������
    result = performOperation(matrix1, matrix2, n, operation);

    // ����� ����������
    printf("Resulting Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", result[i * n + j]);
        }
        printf("\n");
    }

    // ������������ ���������� ������
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}

// ������� ���������� �������� ����� ����� ������-��
double* performOperation(double* matrix1, double* matrix2, int n, char operation) {
    int i, j;
    double* result;

    // ������������ ��������� ������ ��� �������������� �������
    result = (double*)malloc(n * n * sizeof(double));

    // �������� �������� � ���������� ����������
    switch (operation) {
        case '+':
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    result[i * n + j] = matrix1[i * n + j] + matrix2[i * n + j];
                }
            }
            break;
        case '-':
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    result[i * n + j] = matrix1[i * n + j] - matrix2[i * n + j];
                }
            }
            break;
        case '*':
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                	int k;
                    result[i * n + j] = 0;
                    for (k = 0; k < n; k++) {
                        result[i * n + j] += matrix1[i * n + k] * matrix2[k * n + j];
                    }
                }
            }
            break;
        default:
            // ���� �������� �� ������������� �� ������ �� ��������� ������
            printf("Invalid operation.\n");
            return NULL;
    }

    return result;
}
