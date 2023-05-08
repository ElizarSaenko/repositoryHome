#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// ������� ��� ���������� ���������
double calculate(char* str);

int main() {
    char input[1024];

    // ������� ������� ���������
    printf("������� ���������: ");
    fgets(input, 1024, stdin);

    // ������ ������ ����� ������
    input[strcspn(input, "\n")] = '\0';

    // ��������� ���������
    printf("%f\n", calculate(input));

    return 0;
}

double calculate(char* str) {
    double result = 0;
    double temp = 0;
    char* token;
    char* next_token;
    char* operator = "+";

    // ������������ strtok ��� ���������� ������ �� �����
    token = strtok(str, "+-");

    while (token != NULL) {
        // ������������� ������� ��������� � �����
        temp = atof(token);

        // ���������, �������� �� ���������� �������� �������
        if (strlen(operator) == 1) {
            if (operator[0] == '-') {
                temp = -temp;
            }
        }

        // ��������� ��������
        result += temp;

        // ��������� ��������
        next_token = token + strlen(token);
        operator = next_token;

        // ���������� �������
        while (isspace(*next_token)) {
            next_token++;
        }

        // ���������, ��� ��������� ����� ������ - ��������
        if (*next_token == '+' || *next_token == '-') {
            operator = next_token;
        }

        token = strtok(NULL, "+-");
    }

    return result;
}

