#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Функция для вычисления выражения
double calculate(char* str);

int main() {
    char input[1024];

    // Считать входное выражение
    printf("Введите выражение: ");
    fgets(input, 1024, stdin);

    // Убрать символ новой строки
    input[strcspn(input, "\n")] = '\0';

    // Вычислить результат
    printf("%f\n", calculate(input));

    return 0;
}

double calculate(char* str) {
    double result = 0;
    double temp = 0;
    char* token;
    char* next_token;
    char* operator = "+";

    // Использовать strtok для разделения строки на части
    token = strtok(str, "+-");

    while (token != NULL) {
        // Преобразовать текущую подстроку в число
        temp = atof(token);

        // Проверить, является ли предыдущий оператор унарным
        if (strlen(operator) == 1) {
            if (operator[0] == '-') {
                temp = -temp;
            }
        }

        // Выполнить операцию
        result += temp;

        // Следующий оператор
        next_token = token + strlen(token);
        operator = next_token;

        // Пропустить пробелы
        while (isspace(*next_token)) {
            next_token++;
        }

        // Проверить, что следующая часть строки - оператор
        if (*next_token == '+' || *next_token == '-') {
            operator = next_token;
        }

        token = strtok(NULL, "+-");
    }

    return result;
}

