#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
typedef struct 
{ 
 //��������� ��������� ������

    char name[20]; 
    char surname[20]; 
    int year; 
}human; 
 
int compare(const void* a, const void* b) 
{ 
    human* h1 = (human*)a; 
    human* h2 = (human*)b; 
    return h1->year - h2->year; 
} 
 
int main() 
{ 
    FILE* input = fopen("11.txt", "r"); 
    FILE* output = fopen("22.txt", "w"); 
 
    if (input == NULL || output == NULL) 
	{ 
        printf("Your file is empty\n"); 
        return 1; 
    } 
 

    int n = 1; 
    while (!feof(input))  //������ ������� ������� ���������� ���������� �� ����
	{  
        char c = fgetc(input); 
        if (c == '\n')
		{ 
            n++; 
        } 
    } 
    rewind(input);  
 
 //�������� ����� ��� ������ � ������������ ��������
    human* arr1 = (human*)malloc(sizeof(human) * n); 
    human* arr2 = (human*)malloc(sizeof(human) * n); 
	int i; 
    for (i = 0; i < n; i++) 
	{ 
        fscanf(input, "%s %s %d", arr1[i].name, arr1[i].surname, &arr1[i].year); 
    } 
 
    memcpy(arr2, arr1, sizeof(human) * n); 
    qsort(arr2, n, sizeof(human), compare); 
    for (i = 0; i < n; i++) { 
        fprintf(output, "%s %s %d\n", arr2[i].name, arr2[i].surname, arr2[i].year); 
    }
 
                 //��������� ����� 
 //� ����������� �����, �������������� ��� ��������
fclose(input); 
fclose(output); 

free(arr1); 
free(arr2); 

return 0; 
}
