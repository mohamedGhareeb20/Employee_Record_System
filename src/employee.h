#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// Structure definition for an employee
typedef struct Employee {
    char fullName[100];
    int age;
    double salary;
    char title[50];
    int id;
    time_t addedTime;
    struct Employee* next;
} Employee;

// Function declarations
Employee* createEmployee(const char* fullName, int age, double salary, const char* title, int id);
Employee* addEmployee(Employee* head);
Employee* deleteEmployee(Employee* head, int id);
Employee* modifyEmployee(Employee* head, int id);
void viewEmployee(Employee* head, const char* fullName);
void viewAllEmployees(Employee* head);
void ExitEmployee(Employee* head);
char* getTime(time_t timestamp);
#endif /* EMPLOYEE_H */