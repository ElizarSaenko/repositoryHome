int main() {
int i, j;
double sum_main_diagonal, sum_secondary_diagonal;
double matrix [3][3];
int matrix_int [2][2], new_matrix_int [2][2];
printf("Elements of 1 matrica:\n");
for (i = 0; i < 3; i++) {
for (j = 0; j < 3; j++) {
scanf("%lf", &matrix[i][j]);
}
}
printf("First matrica\n");
for (i = 0; i < 3; i++) {
for (j = 0; j < 3; j++) {
printf("%lf\t", matrix[i][j]);
}
printf("\n");
}
sum_main_diagonal = matrix[0][0]+matrix[1][1]+matrix[2][2];
sum_secondary_diagonal = matrix[0][2]+matrix[1][1]+matrix[2][0];
printf("Summa glavnoi: %lf\n", sum_main_diagonal);
printf("Summa pobochka: %lf\n", sum_secondary_diagonal);
printf("Second matrica: \n");
for (i = 0; i < 2; i++) {
for (j = 0; j < 2; j++) {
scanf("%d", &matrix_int[i][j]);
}
}
printf("Preobraz. matrix: \n");
new_matrix_int[0][0]=matrix_int[0][0]*matrix_int[0][0]+matrix_int[1][0]*matrix_int[0][1];
new_matrix_int[0][1]=matrix_int[0][1]*matrix_int[0][1]+matrix_int[1][0]*matrix_int[0][1];
new_matrix_int[1][0]=matrix_int[1][0]*matrix_int[1][0]+matrix_int[1][0]*matrix_int[0][1];
new_matrix_int[1][1]=matrix_int[1][1]*matrix_int[1][1]+matrix_int[1][0]*matrix_int[0][1];
for (i = 0; i < 2; i++) {
for (j = 0; j < 2; j++) {
printf("%d\t", new_matrix_int[i][j]);
}
printf("\n");
}
}
