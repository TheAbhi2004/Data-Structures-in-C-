//Write a program to create a structure to store the information of n number of employees . Employee information includes data members : Emp-id,
//Name,designation, basic salary ,hra%, da%. Display the information of employees with gross salary.Use array of structure  
#include <stdio.h>
#include <string.h>

struct Employee 
{
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
};

void displayEmployeeInfo(struct Employee emp) 
{
    float hra = emp.basic_salary * emp.hra_percent / 100;
    float da = emp.basic_salary * emp.da_percent / 100;
    float gross_salary = emp.basic_salary + hra + da;

    printf("Emp ID: %d\n", emp.emp_id);
    printf("Name: %s\n", emp.name);
    printf("Designation: %s\n", emp.designation);
    printf("Basic Salary: %.2f\n", emp.basic_salary);
    printf("HRA: %.2f\n", hra);
    printf("DA: %.2f\n", da);
    printf("Gross Salary: %.2f\n", gross_salary);
    printf("\n");
}

int main() 
{
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; i++) 
    {
        printf("\nEnter information for employee %d:\n", i + 1);
        printf("Emp ID: ");
        scanf("%d", &employees[i].emp_id);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);   

        printf("HRA Percentage: ");
        scanf("%f", &employees[i].hra_percent);
        printf("DA Percentage: ");
        scanf("%f", &employees[i].da_percent);
    }

    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) 
    {
        displayEmployeeInfo(employees[i]);
    }

    return 0;
}
