#include <stdio.h>

int compareBoxes(int boxA[], int boxB[], int size) {
    int i, j, found;

    // Check for one-to-one mapping of items
    for (i = 0; i < size; i++) {
        found = 0;
        for (j = 0; j < size; j++) {
            if (boxA[i] == boxB[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            return 0; // Mapping not found
        }
    }

    return 1; // One-to-one mapping found
}

int main() {
    int size;

    printf("Enter the size of the boxes: ");
    scanf("%d", &size);

    int boxA[size], boxB[size];

    printf("Enter the items of Box A: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &boxA[i]);
    }

    printf("Enter the items of Box B: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &boxB[i]);
    }

    int result = compareBoxes(boxA, boxB, size);

    if (result == 1) {
        printf("Boxes have one-to-one mapping of items.\n");
    } else {
        printf("Boxes do not have one-to-one mapping of items.\n");
    }

    return 0;
}