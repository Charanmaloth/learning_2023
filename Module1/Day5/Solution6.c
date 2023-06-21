#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENSORS 10
#define MAX_BUFFER_SIZE 100

// Structure to hold sensor data
typedef struct {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
} SensorData;

// Function to parse the data string and populate the array of structures
void parseDataString(const char* dataString, SensorData* sensors, int* numSensors) {
    char buffer[MAX_BUFFER_SIZE];
    char* token;
    char* rest = NULL;

    strcpy(buffer, dataString);

    // Parse sensor data tokens
    token = strtok_r(buffer, "-", &rest);
    while (token != NULL) {
        SensorData* currentSensor = &sensors[*numSensors];

        // Parse sensor ID
        strncpy(currentSensor->sensorID, token, sizeof(currentSensor->sensorID));
        currentSensor->sensorID[sizeof(currentSensor->sensorID) - 1] = '\0';

        // Parse temperature
        token = strtok_r(NULL, ":T", &rest);
        currentSensor->temperature = atof(token);

        // Parse humidity
        token = strtok_r(NULL, ":H", &rest);
        currentSensor->humidity = atoi(token);

        // Parse light intensity
        token = strtok_r(NULL, ":L", &rest);
        currentSensor->lightIntensity = atoi(token);

        (*numSensors)++;

        token = strtok_r(NULL, "-", &rest);
    }
}

// Function to display the parsed sensor data
void displaySensorData(const SensorData* sensors, int numSensors) {
    printf("Sensor Info:\n");
    printf("---------------------\n");

    for (int i = 0; i < numSensors; i++) {
        const SensorData* currentSensor = &sensors[i];

        printf("Sensor ID: %s\n", currentSensor->sensorID);
        printf("Temperature: %.1f C\n", currentSensor->temperature);
        printf("Humidity: %d\n", currentSensor->humidity);
        printf("Light Intensity: %d%%\n", currentSensor->lightIntensity);

        printf("---------------------\n");
    }
}

int main() {
    char dataString[MAX_BUFFER_SIZE];
    SensorData sensors[MAX_SENSORS];
    int numSensors = 0;

    printf("Enter the data string: ");
    fgets(dataString, sizeof(dataString), stdin);

    // Remove the trailing newline character from fgets
    dataString[strcspn(dataString, "\n")] = '\0';

    parseDataString(dataString, sensors, &numSensors);
    displaySensorData(sensors, numSensors);

    return 0;
}