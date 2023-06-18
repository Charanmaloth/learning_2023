#include <stdio.h>

char *xstrchr(char *string, char ch) {
    while (*string != '\0') {
        if (*string == ch) {
            return string;
        }
        string++;
    }
    return NULL;
}

int main() {
    char string[100];
    char ch;

    printf("Enter a string: ");
    scanf("%s", string);

    printf("Enter a character to search: ");
    scanf(" %c", &ch);

    char *result = xstrchr(string, ch);

    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", ch, result - string + 1);
    } else {
        printf("Character '%c' not found in the string.\n", ch);
    }

    return 0;
}