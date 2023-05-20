#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int result, n;
    printf("Vvedite kolichestvo of numbers: ");
    scanf("%d", &n);

    int arr[n], i;
    printf("Vvedite numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    result = arr[0];
    for (i = 1; i < n; i++) {
        result = MAX(result, arr[i]);
    }

    printf("MAX of us: %d", result);

    return 0;
}

