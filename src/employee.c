#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "employee.h"

// Function to create a new employee
Employee* createEmployee(const char* fullName, int age, double salary, const char* title, int id) {
    Employee* employee = (Employee*)malloc(sizeof(Employee));
    strcpy(employee->fullName, fullName);
    employee->age = age;
    employee->salary = salary;
    strcpy(employee->title, title);
    employee->id = id;
    employee->next = NULL;
    return employee;
}

// Function to add a new employee to the linked list
Employee* addEmployee(Employee* head) {
    char fullName[100];
    int age, id;
    double salary;
    char title[50];

    printf("Enter the full name of the employee: ");
    getchar(); 
    fgets(fullName, sizeof(fullName), stdin);
    fullName[strcspn(fullName, "\n")] = '\0'; 

    printf("Enter the age of the employee: ");
    scanf("%d", &age);
    printf("Enter the salary of the employee: ");
    scanf("%lf", &salary);
    printf("Enter the title of the employee: ");
    getchar(); 
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; 

    printf("Enter the ID of the employee: ");
    scanf("%d", &id);

    Employee* newEmployee = createEmployee(fullName, age, salary, title, id);
    newEmployee->addedTime = time(NULL);

    if (head == NULL) {
        head = newEmployee;
    } else {
        Employee* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEmployee;
    }

    printf("Employee added successfully.\n");

    return head;
}

// Function to delete an employee from the linked list by "ID"
Employee* deleteEmployee(Employee* head, int id) {
    if (head == NULL) {
        printf("Employee list is empty. Deletion failed.\n");
        return NULL;
    }

    if (head->id == id) {
        Employee* temp = head;
        head = head->next;
        free(temp);
        printf("Employee withID %d deleted successfully.\n", id);
        return head;
    }

    Employee* current = head;
    Employee* prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Employee with ID %d not found. Deletion failed.\n", id);
        return head;
    }

    prev->next = current->next;
    free(current);

    printf("Employee with ID %d deleted successfully.\n", id);

    return head;
}

// Function to modify an employee in the linked list by "ID"
Employee* modifyEmployee(Employee* head, int id) {
    if (head == NULL) {
        printf("Employee list is empty. Modification failed.\n");
        return NULL;
    }

    Employee* current = head;

    while (current != NULL && current->id != id) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Employee with ID %d not found. Modification failed.\n", id);
        return head;
    }

    printf("Enter the new full name of the employee: ");
    getchar(); 
    fgets(current->fullName, sizeof(current->fullName), stdin);
    current->fullName[strcspn(current->fullName, "\n")] = '\0'; 

    printf("Enter the new age of the employee: ");
    scanf("%d", &current->age);
    printf("Enter the new salary of the employee: ");
    scanf("%lf", &current->salary);

    printf("Enter the new title of the employee: ");
    getchar(); 
    fgets(current->title, sizeof(current->title), stdin);
    current->title[strcspn(current->title, "\n")] = '\0'; 

    printf("Employee with ID %d modified successfully.\n", id);

    return head;
}

// Function to view an employee by "name"
void viewEmployee(Employee* head, const char* fullName) {
    Employee* current = head;
    int found = 0;

    while (current != NULL) {
        if (strcmp(current->fullName, fullName) == 0) {
            printf("Employee ID: %d\n", current->id);
            printf("Full Name: %s\n", current->fullName);
            printf("Age: %d\n", current->age);
            printf("Salary: %.2lf\n", current->salary);
            printf("Title: %s\n", current->title);
            printf("[Added Time]: %s", getTime(current->addedTime));
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Employee not found.\n");
    }
}

// Function to view all employees in the linked list
void viewAllEmployees(Employee* head) {
    if (head == NULL) {
        printf("Employee list is empty.\n");
        return;
    }

    printf("Employee List:\n");

    Employee* current = head;

    while (current != NULL) {
        printf("-------------------\n");
        printf("Employee ID: %d\n", current->id);
        printf("Full Name: %s\n", current->fullName);
        printf("Age: %d\n", current->age);
        printf("Salary: %.2lf\n", current->salary);
        printf("Title: %s\n", current->title);
        printf("[Added Time]: %s", getTime(current->addedTime));
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list
void ExitEmployee(Employee* head) {
    Employee* current = head;
    Employee* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

char* getTime(time_t timestamp) {
    return ctime(&timestamp);
}