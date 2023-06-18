#include <stdio.h>

// Function to set a bit at a given position
unsigned char setBit(unsigned char num, int position) {
    return num | (1 << position);
}

// Function to clear a bit at a given position
unsigned char clearBit(unsigned char num, int position) {
    return num & (~(1 << position));
}

// Function to toggle a bit at a given position
unsigned char toggleBit(unsigned char num, int position) {
    return num ^ (1 << position);
}

// Main function
int main() {
    unsigned char number;
    int position;
    
    printf("Enter an 8-bit number (0-255): ");
    scanf("%hhu", &number);
    
    printf("Enter the position of the bit (0-7): ");
    scanf("%d", &position);
    
    if (position >= 0 && position <= 7) {
        printf("Number after setting the bit: %hhu\n", setBit(number, position));
        printf("Number after clearing the bit: %hhu\n", clearBit(number, position));
        printf("Number after toggling the bit: %hhu\n", toggleBit(number, position));
    } else {
        printf("Invalid position! Please enter a value between 0 and 7.\n");
    }
    
    return 0;
}