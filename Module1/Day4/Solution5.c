#include <stdio.h>

int main() {
    int size, i;
    int evenSum = 0, oddSum = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < size; i++) {
        if (i % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddSum += arr[i];
        }
    }

    printf("Sum of even-indexed elements: %d\n", evenSum);
    printf("Sum of odd-indexed elements: %d\n", oddSum);
    printf("Difference: %d\n", evenSum - oddSum);

    return 0;
}