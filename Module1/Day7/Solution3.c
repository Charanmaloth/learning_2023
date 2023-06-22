#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
};

void extractLogEntries(struct LogEntry logEntries[], int *numEntries) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open data.csv\n");
        exit(1);
    }

    char line[100];
    int count = 0;

    // Skip the header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) != NULL) {
        // Extract each field from the line
        struct LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,\n]", &entry.entryNo, entry.sensorNo, &entry.temperature, &entry.humidity, &entry.light, entry.time);

        // Store the entry in the array
        logEntries[count] = entry;
        count++;

        if (count >= MAX_ENTRIES) {
            printf("Exceeded maximum number of entries.\n");
            break;
        }
    }

    *numEntries = count;

    fclose(file);
}

void displayLogEntries(struct LogEntry logEntries[], int numEntries) {
    printf("Log Entries:\n");
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    int i;
    for (i = 0; i < numEntries; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n", logEntries[i].entryNo, logEntries[i].sensorNo, logEntries[i].temperature, logEntries[i].humidity, logEntries[i].light, logEntries[i].time);
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractLogEntries(logEntries, &numEntries);
    displayLogEntries(logEntries, numEntries);

    return 0;
}
