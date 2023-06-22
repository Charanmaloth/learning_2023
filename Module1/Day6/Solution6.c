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

// Function to add a member at the end of the array of structures
void addMember(Student** students, int* numStudents) {
    // Increment the number of students
    (*numStudents)++;

    // Reallocate memory for the increased number of students
    students = (Student)realloc(*students, (*numStudents) * sizeof(Student));

    // Read new student information
    printf("Enter details for new student:\n");

    printf("Roll No: ");
    scanf("%d", &((*students)[*numStudents - 1].rollno));

    printf("Name: ");
    scanf("%s", (*students)[*numStudents - 1].name);

    printf("Marks: ");
    scanf("%f", &((*students)[*numStudents - 1].marks));
}

int main() {
    Student* students = NULL;
    int numStudents = 0;
    int choice;

    do {
        printf("\n1. Add a member\n");
        printf("2. Display all members\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a member at the end of the array
                addMember(&students, &numStudents);
                break;
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

    // Free the memory allocated for the students
    free(students);

    return 0;
}