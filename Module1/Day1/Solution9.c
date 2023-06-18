#include <stdio.h>
#include <ctype.h>

int findCharType(char c) {
    int type;

    if (isalpha(c)) {
        if (isupper(c)) {
            type = 1; // Uppercase letter
        } else {
            type = 2; // Lowercase letter
        }
    } else if (isdigit(c)) {
        type = 3; // Digit
    } else if (isprint(c)) {
        type = 4; // Printable symbol
    } else {
        type = 5; // Non-printable symbol
    }

    return type;
}

int main() {
    char c;

    printf("Enter a character: ");
    scanf(" %c", &c);

    int type = findCharType(c);

    switch (type) {
        case 1:
            printf("Type: Uppercase letter\n");
            break;
        case 2:
            printf("Type: Lowercase letter\n");
            break;
        case 3:
            printf("Type: Digit\n");
            break;
        case 4:
            printf("Type: Printable symbol\n");
            break;
        case 5:
            printf("Type: Non-printable symbol\n");
            break;
        default:
            printf("Type: Unknown\n");
            break;
    }

    return 0;
}