#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AVERAGE(arr) ((arr[0]+arr[1]+arr[2]+arr[3]+arr[4])/5.0)

int main() {
    char input[1000];
    printf("Vvedite numbers: ");
    fgets(input, sizeof(input), stdin);

    int n = 0;
    int arr[5];
    char *token = strtok(input, " ");
    while (token != NULL && n < 5) {
        arr[n++] = atoi(token);
        token = strtok(NULL, " ");
    }

    double result = AVERAGE(arr);
    printf("Srednee: %lf\n", result);

    return 0;
}
