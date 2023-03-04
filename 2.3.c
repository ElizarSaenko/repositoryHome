#include <stdio.h>

int main()
{
    double sum1, sum;
    int i, j;
    double a[3][3];
    int b [2][2], newarr [2][2];
    printf("Ёлементы матрицы:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &a[i][j]);
            }
    }
printf("¬веденна€ матрица:\n");
 for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%lf\t", a[i][j]);
        }
        printf("\n");
    }
 sum1 = a[0][0]+a[1][1]+a[2][2];
 sum2 = a[0][2]+a[1][1]+a[2][0];
 printf("—умма главной диагонали: %lf\n", sum1);
 printf("—умма побочной диагонали: %lf\n", sum2);
 printf("¬вод данных второй матрицы:\n");
 for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        scanf("%d", &b[i][j]);
        }
    } 
 printf(" вадрат второй матрицы:\n");
 newarr[0][0]=b[0][0]*b[0][0]+b[1][0]*b[0][1];
 newarr[0][1]=b[0][1]*b[0][1]+b[1][0]*b[0][1];
 newarr[1][0]=b[1][0]*b[1][0]+b[1][0]*b[0][1];
 newarr[1][1]=b[1][1]*b[1][1]+b[1][0]*b[0][1];
 for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        printf("%d\t", newarr[i][j]);
        }
    printf("\n");
    }
 return 0;
}
