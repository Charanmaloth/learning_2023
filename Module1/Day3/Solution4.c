#include <stdio.h>

int findSmallestDigit(int num) {
    int smallest = 9;
    
    while (num > 0) {
        int digit = num % 10;
        if (digit < smallest)
            smallest = digit;
        
        num /= 10;
    }
    
    return smallest;
}

int findLargestDigit(int num) {
    int largest = 0;
    
    while (num > 0) {
        int digit = num % 10;
        if (digit > largest)
            largest = digit;
        
        num /= 10;
    }
    
    return largest;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Not Valid\n");
        return 0;
    }
    
    int i;
    int smallest, largest;
    int num;
    
    printf("Enter %d numbers:\n", n);
    
    for (i = 1; i <= n; i++) {
        printf("n%d: ", i);
        scanf("%d", &num);
        
        if (i == 1) {
            smallest = findSmallestDigit(num);
            largest = findLargestDigit(num);
        } else {
            int currSmallest = findSmallestDigit(num);
            int currLargest = findLargestDigit(num);
            
            if (currSmallest < smallest)
                smallest = currSmallest;
            
            if (currLargest > largest)
                largest = currLargest;
        }
    }
    
    printf("Smallest digit: %d\n", smallest);
    printf("Largest digit: %d\n", largest);
    
    return 0;
}