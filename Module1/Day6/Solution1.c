#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int rollno;
    char name[20];
    float marks;
};

void parseString(char *inputString, struct Student *students, int numStudents) {
    char *token = strtok(inputString, " ");
    int i = 0;

    while (token != NULL && i < numStudents) {
        students[i].rollno = atoi(token);
        token = strtok(NULL, " ");
        strncpy(students[i].name, token, sizeof(students[i].name));
        token = strtok(NULL, " ");
        students[i].marks = atof(token);
        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Flush the newline character from the input buffer
    getchar();

    struct Student *students = malloc(numStudents * sizeof(struct Student));

    printf("Enter the student details:\n");

    for (int i = 0; i < numStudents; i++) {
        char inputString[100];
        fgets(inputString, sizeof(inputString), stdin);
        inputString[strcspn(inputString, "\n")] = '\0';  // Remove newline character

        parseString(inputString, &students[i], numStudents);
    }

    // Print the initialized array of structures
    printf("\nStudent Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n",
               students[i].rollno, students[i].name, students[i].marks);
    }

    free(students);
    return 0;
}
