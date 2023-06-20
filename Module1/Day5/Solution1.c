#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

void calculateBoxProperties(struct Box *box) {
    double volume = box->length * box->width * box->height;
    double surfaceArea = 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
    
    printf("Volume of the box: %.2f\n", volume);
    printf("Total surface area of the box: %.2f\n", surfaceArea);
}

int main() {
    struct Box myBox;
    
    printf("Enter the length of the box: ");
    scanf("%lf", &(myBox.length));
    
    printf("Enter the width of the box: ");
    scanf("%lf", &(myBox.width));
    
    printf("Enter the height of the box: ");
    scanf("%lf", &(myBox.height));
    
    calculateBoxProperties(&myBox);
    
    return 0;
}
