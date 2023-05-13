#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char first_name[50];
    char last_name[50];
    int birth_year;
    char gender;
    float height;
} Person;

int compare(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    // Сортировка по году рождения
    if (person_a->birth_year != person_b->birth_year) {
        return person_a->birth_year - person_b->birth_year;
    }

    // Сортировка по имени
    int cmp = strcmp(person_a->first_name, person_b->first_name);
    if (cmp != 0) {
        return cmp;
    }

    // Сортировка по фамилии
    cmp = strcmp(person_a->last_name, person_b->last_name);
    if (cmp != 0) {
        return cmp;
    }

    // Сортировка по полу
    if (person_a->gender != person_b->gender) {
        return person_a->gender - person_b->gender;
    }

    // Сортировка по росту
    if (person_a->height != person_b->height) {
        return person_a->height > person_b->height ? 1 : -1;
    }

    return 0;
}

int main() {
    FILE *in_file, *out_file;
    in_file = fopen("people.txt", "r");
    if (in_file == NULL) {
        printf("Error opening input file.");
        exit(1);
    }
    out_file = fopen("sorted_people.txt", "w");
    if (out_file == NULL) {
        printf("Error opening output file.");
        exit(1);
    }

    Person people[100];
    int i = 0;
    while (fscanf(in_file, "%s %s %d %c %f", people[i].first_name, people[i].last_name, &people[i].birth_year, &people[i].gender, &people[i].height) != EOF) {
        i++;
    }
    int num_people = i;

    char sort_params[50];
    printf("Enter sort parameters (e.g. 'by_birth_year by_name by_last_name by_gender by_height'): ");
    fgets(sort_params, 50, stdin);

    char *param = strtok(sort_params, " ");
    while (param != NULL) {
        if (strcmp(param, "by_birth_year") == 0) {
            qsort(people, num_people, sizeof(Person), compare);
        } else if (strcmp(param, "by_name") == 0) {
            qsort(people, num_people, sizeof(Person), compare);
        } else if (strcmp(param, "by_last_name") == 0) {
            qsort(people, num_people, sizeof(Person), compare);
        } else if (strcmp(param, "by_gender") == 0) {
            qsort(people, num_people, sizeof(Person), compare);
        } else if (strcmp(param, "by_height") == 0) {
            qsort(people, num_people, sizeof(Person), compare);
        } else {
            printf("Invalid sort parameter: %s\n", param);
        }
        param = strtok(NULL, " ");
    }

    for (i = 0; i < num_people; i++) {
        fprintf(out_file, "%s %s %d %c %.2f\n", people[i].first_name, people[i].last_name, people[i].birth_year, people[i].gender, people[i].height);
    }

    fclose(in_file);
    fclose(out_file);
    return 0;
}
