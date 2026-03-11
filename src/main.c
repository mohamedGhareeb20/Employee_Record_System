#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "employee.h"

int main() {
    Employee* head = NULL;
    int choice;
    int id;
    char fullName[100];

    do {
        printf("Welcome to our company System\n");
        printf("----------------------------------\n");
        printf("1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Modify Employee\n");
        printf("4. View Employee\n");
        printf("5. View All Employees\n");
        printf("6. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addEmployee(head);
                break;
            case 2:
                printf("Enter the ID of the employee to delete: ");
                scanf("%d", &id);
                head = deleteEmployee(head, id);
                break;
            case 3:
                printf("Enter the ID of the employee to modify: ");
                scanf("%d", &id);
                head = modifyEmployee(head, id);
                break;
            case 4:
                printf("Enter the full name of the employee to view: ");
                getchar(); 
                fgets(fullName, sizeof(fullName), stdin);
                fullName[strcspn(fullName, "\n")] = '\0'; 
                viewEmployee(head, fullName);
                break;
            case 5:
                viewAllEmployees(head);
                break;
            case 6:
                ExitEmployee(head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
        printf("Do you want to do any other operation? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}