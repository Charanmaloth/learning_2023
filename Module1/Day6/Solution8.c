#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50

// Structure to represent student information
typedef struct {
    int rollno;
    char name[20];
    float marks;
} Student;

// Function to swap two members in different indexes of the array of structures
void swapMembers(Student* students, int index1, int index2) {
    Student temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
    printf("Members swapped successfully.\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        printf("\n1. Swap members\n");
        printf("2. Display all members\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Swap members based on user input
                int index1, index2;
                printf("Enter the indexes of the members to swap (starting from 0): ");
                scanf("%d %d", &index1, &index2);

                if (index1 >= 0 && index1 < numStudents && index2 >= 0 && index2 < numStudents) {
                    swapMembers(students, index1, index2);
                } else {
                    printf("Invalid indexes. Try again.\n");
                }
                break;
            }
            case 2:
                // Display all members
                printf("\nAll members:\n");
                for (int i = 0; i < numStudents; i++) {
                    printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollno, students[i].name, students[i].marks);
                }
                break;
            case 3:
                // Quit the program
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}