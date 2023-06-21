#include <stdio.h>

#define MAX_STUDENTS 50

// Structure to represent student information
typedef struct {
    char name[50];
    int marks;
} Student;

// Function to read student information from the user
void readStudentData(Student* student, int numStudents) {
    printf("Enter details for Student %d:\n", numStudents + 1);
    printf("Name: ");
    scanf("%s", student->name);
    printf("Marks: ");
    scanf("%d", &(student->marks));
}

// Function to calculate the average marks for a class of students
float calculateAverageMarks(const Student* students, int numStudents) {
    int sum = 0;

    for (int i = 0; i < numStudents; i++) {
        sum += students[i].marks;
    }

    return (float)sum / numStudents;
}

// Function to display the students who scored above and below the average marks
void displayStudentsAboveBelowAverage(const Student* students, int numStudents, float averageMarks) {
    printf("\nStudents above the average marks:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks > averageMarks) {
            printf("%s\n", students[i].name);
        }
    }

    printf("\nStudents below the average marks:\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks < averageMarks) {
            printf("%s\n", students[i].name);
        }
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents;
    float averageMarks;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Validate the number of students
    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Exiting the program.\n");
        return 1;
    }

    // Read student information
    for (int i = 0; i < numStudents; i++) {
        readStudentData(&students[i], i);
    }

    // Calculate average marks
    averageMarks = calculateAverageMarks(students, numStudents);

    // Display students above and below average marks
    displayStudentsAboveBelowAverage(students, numStudents, averageMarks);

    return 0;
}