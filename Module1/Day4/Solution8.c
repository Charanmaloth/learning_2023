#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char timeStr[9];  // Assuming the maximum length of the time string is 8 characters
    char *token;
    unsigned long hh, mm, ss;
    unsigned long totalSeconds;

    printf("Enter the time in hh:mm:ss format: ");
    fgets(timeStr, sizeof(timeStr), stdin);

    // Split the time string into hours, minutes, and seconds using strtok()
    token = strtok(timeStr, ":");
    hh = strtoul(token, NULL, 10);

    token = strtok(NULL, ":");
    mm = strtoul(token, NULL, 10);

    token = strtok(NULL, ":");
    ss = strtoul(token, NULL, 10);

    // Compute the total number of seconds
    totalSeconds = hh * 3600 + mm * 60 + ss;

    printf("Total seconds: %lu\n", totalSeconds);

    return 0;
}