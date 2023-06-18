#include <stdio.h>

// Function to print the bits of a 32-bit integer
void printBits(unsigned int num) {
    int i;
    unsigned int mask = 1 << 31; // Start with the leftmost bit
    
    for (i = 0; i < 32; i++) {
        // Use bitwise AND to check if the bit is set
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }
        
        // Shift the mask to the right
        mask = mask >> 1;
    }
    
    printf("\n");
}

// Main function
int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);
    
    printBits(num);
    
    return 0;
}
