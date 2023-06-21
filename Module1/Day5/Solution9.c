#include <stdio.h>
#include <stdlib.h>

// Structure to represent student information
typedef struct {
    char name[50];
    int age;
} Student;

// Function to modify the members of a structure through a pointer
void modifyStudentInfo(Student* student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter student age: ");
    scanf("%d", &(student->age));
}

// Function to allocate memory for a new student and return a pointer to it
Student* createNewStudent() {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    return newStudent;
}

int main() {
    Student* studentPtr;

    // Create a new student
    studentPtr = createNewStudent();

    // Modify student information
    modifyStudentInfo(studentPtr);

    // Display modified student information
    printf("\nModified student information:\n");
    printf("Name: %s\n", studentPtr->name);
    printf("Age: %d\n", studentPtr->age);

    // Free the memory allocated for the student
    free(studentPtr);

    return 0;
}