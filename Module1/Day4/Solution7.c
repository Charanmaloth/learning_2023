#include <stdio.h>

int main() {
    char str[100];
    int i = 0;
    int res = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0' && str[i] != '\n') {
        int ival = str[i] - '0';
        res = res * 10 + ival;
        i++;
    }

    printf("Converted integer value: %d\n", res);

    return 0;
}