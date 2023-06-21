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

// Function to delete a member at the start of the array of structures
void deleteMember(Student** students, int* numStudents) {
    if (*numStudents > 0) {
        // Shift all members to the left
        for (int i = 0; i < (*numStudents) - 1; i++) {
            (*students)[i] = (*students)[i + 1];
        }

        // Decrement the number of students
        (*numStudents)--;

        // Reallocate memory for the reduced number of students
        students = (Student)realloc(*students, (*numStudents) * sizeof(Student));

        printf("Member deleted successfully.\n");
    } else {
        printf("No members to delete.\n");
    }
}

int main() {
    Student* students = NULL;
    int numStudents = 0;
    int choice;

    do {
        printf("\n1. Delete a member\n");
        printf("2. Display all members\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Delete a member from the start of the array
                deleteMember(&students, &numStudents);
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