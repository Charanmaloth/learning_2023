#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* str) {
    int length = strlen(str);
    int i, j;
    char temp;
    
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
void inc(char* s) {
    printf("%s", s);
}

void space(int x) {
    int i;
    for (i = 0; i < 2 * x; i++) {
        printf(" ");
    }
}
/* Rest of the code remains the same */

void printPattern(int n) {
    char str[10];
    char rev[10];
    int i, j;

    sprintf(str, "%d", 1);
    for (i = 2; i <= n; i++) {
        char temp[10];
        sprintf(temp, "%d", i);
        strcat(str, temp);
    }

    strcpy(rev, str);
    reverseString(rev);

    for (i = 0; i < n; i++) {
        inc(str);
        space(i);
        dec(rev);

        str[strlen(str) - 1] = '\0';
        memmove(rev, rev + 1, strlen(rev));
    }
}
void dec(char* s) {
    printf("%s\n", s);
}


int main() {
    int n ;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printPattern(n);


    return 0;
}
