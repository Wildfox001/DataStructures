#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i;
    float total = 0;

    struct employee *emp;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    emp = (struct employee *)malloc(n * sizeof(struct employee));

    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }


    for (i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf("%s", emp[i].name);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);

        total += emp[i].salary;
    }


    printf("\nTotal Monthly Salary Expenditure = %.2f\n", total);
    printf("Total Annual Expenditure = %.2f\n", total * 12);

