#include <stdio.h>

int isVowel(char c) {
    int isVowel = 0; // Default: not a vowel

    switch (c) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            isVowel = 1;
            break;
    }

    return isVowel;
}

int main() {
    char c;

    printf("Enter a character: ");
    scanf(" %c", &c);

    int result = isVowel(c);

    if (result == 1) {
        printf("Vowel\n");
    } else {
        printf("Not Vowel\n");
    }

    return 0;
}