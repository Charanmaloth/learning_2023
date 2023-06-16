#include <stdio.h>

// Function to find the largest number by deleting a single digit
int findLargestNumber(int num) {
    int largest = 0;
    int divisor = 1;
    
    while (divisor <= num) {
        int truncatedNum = (num / (divisor * 10)) * divisor + (num % divisor);
        
        if (truncatedNum > largest) {
            largest = truncatedNum;
        }
        
        divisor *= 10;
    }
    
    return largest;
}

// Main function
int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    
    if (num >= 1000 && num <= 9999) {
        int largestNumber = findLargestNumber(num);
        printf("The largest number after deleting a single digit: %d\n", largestNumber);
    } else {
        printf("Invalid input! Please enter a 4-digit number.\n");
    }
    
    return 0;
}