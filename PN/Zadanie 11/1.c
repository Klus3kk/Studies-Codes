#include <stdio.h>
#include <string.h>

typedef struct {
    char surname[50];
    double salary;
} Employee;

Employee employees[50];
int num_employees = 0;

void read_employees() {
    char filename[50];
    printf("Enter the file name: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    fscanf(file, "%d", &num_employees);
    for (int i = 0; i < num_employees; i++) {
        fscanf(file, "%s %lf", employees[i].surname, &employees[i].salary);
    }
    fclose(file);
}

void new_employee() {
    printf("Enter the surname and salary: ");
    scanf("%s %lf", employees[num_employees].surname, &employees[num_employees].salary);
    num_employees++;
}

void display_employees() {
    for (int i = 0; i < num_employees; i++) {
        printf("%s %lf\n", employees[i].surname, employees[i].salary);
    }
}

void save_employees() {
    char filename[50];
    printf("Enter the file name: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    fprintf(file, "%d\n", num_employees);
    for (int i = 0; i < num_employees; i++) {
        fprintf(file, "%s %lf\n", employees[i].surname, employees[i].salary);
    }
    fclose(file);
}

int main() {
    char command;
    while (1) {
        printf("Enter a command: ");
        scanf(" %c", &command);
        switch (command) {
            case 'R': read_employees(); break;
            case 'N': new_employee(); break;
            case 'W': display_employees(); break;
            case 'Z': save_employees(); break;
            case 'K': return 0;
        }
    }
}