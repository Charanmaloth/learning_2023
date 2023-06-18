#include <stdio.h>
#include <string.h>

void encodeString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] += 1; // Increment ASCII value of each character by 1
    }
}

void decodeString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] -= 1; // Decrement ASCII value of each character by 1
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    encodeString(str);
    printf("Encoded string: %s\n", str);

    decodeString(str);
    printf("Decoded string: %s\n", str);

    return 0;
}