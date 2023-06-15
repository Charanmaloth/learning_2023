#include <stdio.h>
int findMaxUsingIfElse(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
int findMaxUsingTernaryOperator(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    int maxIfElse = findMaxUsingIfElse(num1, num2);
    int maxTernary = findMaxUsingTernaryOperator(num1, num2);

    printf("Using if-else, the biggest number is: %d\n", maxIfElse);
    printf("Using ternary operator, the biggest number is: %d\n", maxTernary);

    return 0;
}
