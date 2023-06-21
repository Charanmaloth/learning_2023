#include <stdio.h>
#include <math.h>

// Structure to represent a Cartesian coordinate point
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double calculateDistance(Point p1, Point p2) {
    double distance;

    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    return distance;
}

int main() {
    Point point1, point2;
    double distance;

    printf("Enter the coordinates of the first point (x y): ");
    scanf("%lf %lf", &point1.x, &point1.y);

    printf("Enter the coordinates of the second point (x y): ");
    scanf("%lf %lf", &point2.x, &point2.y);

    distance = calculateDistance(point1, point2);

    printf("The distance between the points is: %.2lf\n", distance);

    return 0;
}