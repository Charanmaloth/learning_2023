#include <stdio.h>

// Function to convert decimal to BCD
unsigned char decimalToBCD(unsigned char decimal) {
    unsigned char tens = decimal / 10;   // Extract tens digit
    unsigned char ones = decimal % 10;   // Extract ones digit
    
    return (tens << 4) | ones;           // Combine tens and ones digits
}

// Main function
int main() {
    unsigned char decimal;
    
    printf("Enter a decimal number (0-99): ");
    scanf("%hhu", &decimal);
    
    if (decimal >= 0 && decimal <= 99) {
        unsigned char bcd = decimalToBCD(decimal);
        printf("BCD representation: 0x%02X\n", bcd);
    } else {
        printf("Invalid number! Please enter a value between 0 and 99.\n");
    }
    
    return 0;
}