#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *sourceFile, *targetFile;
    char sourceFileName[100], targetFileName[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Get the source file name from the user
    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "rb");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Get the target file name from the user
    printf("Enter the target file name: ");
    scanf("%s", targetFileName);

    // Open the target file in write mode
    targetFile = fopen(targetFileName, "wb");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of the source file to the target file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, targetFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
