#include <stdio.h>

struct Complex {
    double real;
    double imag;
};

void readComplex(struct Complex *c) {
    printf("Enter the real part: ");
    scanf("%lf", &(c->real));
    
    printf("Enter the imaginary part: ");
    scanf("%lf", &(c->imag));
}

void writeComplex(struct Complex c) {
    if (c.imag < 0) {
        printf("Complex number: %.2f - %.2fi\n", c.real, -c.imag);
    } else {
        printf("Complex number: %.2f + %.2fi\n", c.real, c.imag);
    }
}

struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    struct Complex complex1, complex2, sum, product;
    
    printf("Reading the first complex number:\n");
    readComplex(&complex1);
    
    printf("\nReading the second complex number:\n");
    readComplex(&complex2);
    
    printf("\nComplex numbers entered:\n");
    writeComplex(complex1);
    writeComplex(complex2);
    
    sum = addComplex(complex1, complex2);
    printf("\nSum of the complex numbers:\n");
    writeComplex(sum);
    
    product = multiplyComplex(complex1, complex2);
    printf("\nProduct of the complex numbers:\n");
    writeComplex(product);
    
    return 0;
}