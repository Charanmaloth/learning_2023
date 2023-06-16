#include <stdio.h>

void printExponent(double x) {
    // Get the address of the double variable
    unsigned long long* ptr = (unsigned long long*)&x;

    // Extract the exponent part from the binary representation
    unsigned int exponent = (*ptr >> 52) & 0x7FF;

    // Print exponent in hexadecimal format
    printf("Hexadecimal exponent: 0x%03X\n", exponent);

    // Print exponent in binary format
    printf("Binary exponent: 0b");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x;
    printf("Enter a double value: ");
    scanf("%lf", &x);

    printExponent(x);

   return 0;
}
