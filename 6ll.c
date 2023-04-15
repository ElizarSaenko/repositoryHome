#include <stdio.h>

int main() {
FILE *input_file, *output_file;
char name[50], surname[50], patronymic[50];
int year;

input_file = fopen("input.txt", "r");
output_file = fopen("output.txt", "w");

if (input_file == NULL || output_file == NULL) {
printf("Error opening file\n");
return 1;
}

while (fscanf(input_file, "%s %s %s %d", surname, name, patronymic, &year) != EOF) {
if (year > 1980) {
fprintf(output_file, "%s %s %s %d\n", surname, name, patronymic, year);
}
}

fclose(input_file);
fclose(output_file);

return 0;
}
