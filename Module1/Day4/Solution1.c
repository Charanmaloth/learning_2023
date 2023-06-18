#include <stdio.h>

int main() {
    int size, i;
    float sum = 0, average;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = sum / size;

    printf("Sum of the array elements: %.2f\n", sum);
    printf("Average of the array elements: %.2f\n", average);

    return 0;
}
