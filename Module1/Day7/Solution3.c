#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

void extractLogEntries(LogEntry logEntries[], int* numEntries) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    int entryCount = 0;

    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    // Read each line from the file and extract the log entry details
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        token = strtok(line, ",");
        logEntries[entryCount].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].sensorNo, token);

        token = strtok(NULL, ",");
        logEntries[entryCount].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[entryCount].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[entryCount].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].time, token);

        entryCount++;
    }

    *numEntries = entryCount;

    fclose(file);
}

void displayLogEntries(LogEntry logEntries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].time);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractLogEntries(logEntries, &numEntries);
    displayLogEntries(logEntries, numEntries);

    return 0;
}