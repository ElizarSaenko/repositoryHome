#include <stdio.h>
#include <stdlib.h>

// объ€вление функции, котора€ будет выполн€ть операцию с матрицами
double* performOperation(double* matrix1, double* matrix2, int n, char operation);

int main() {
    int n, i, j;
    char operation;
    double* matrix1;
    double* matrix2;
    double* result;

    // запрос размерности матриц
    printf("Enter the dimension of the matrices (N): ");
    scanf("%d", &n);

    // динамическое выделение пам€ти
    matrix1 = (double*)malloc(n * n * sizeof(double));
    matrix2 = (double*)malloc(n * n * sizeof(double));

    // запрос элементов первой матрицы
    printf("Enter the elements of the first matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i * n + j]);
        }
    }

    // запрос элементов второй матрицы
    printf("Enter the elements of the second matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &matrix2[i * n + j]);
        }
    }

    // запрос операции
    printf("Enter the operation (+, -, or *): ");
    scanf(" %c", &operation);

    // вызов функции, котора€ вычисл€ет операцию и возвращает результат
    result = performOperation(matrix1, matrix2, n, operation);

    // вывод результата
    printf("Resulting Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", result[i * n + j]);
        }
        printf("\n");
    }

    // освобождение выделенной пам€ти
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}

// функци€ выполнени€ операции между двум€ матриц-ми
double* performOperation(double* matrix1, double* matrix2, int n, char operation) {
    int i, j;
    double* result;

    // динамическое выделение пам€ти дл€ результирующей матрицы
    result = (double*)malloc(n * n * sizeof(double));

    // проверка операции и вычисление результата
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
            // если операци€ не соответствует ни одному из требуемых знаков
            printf("Invalid operation.\n");
            return NULL;
    }

    return result;
}
