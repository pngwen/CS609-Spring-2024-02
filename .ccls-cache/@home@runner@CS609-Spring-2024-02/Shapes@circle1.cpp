// circle.cpp
#include "circle.h"

// Constructor
Circle::Circle(double x, double y, double radius)
    : x(x), y(y), radius(radius) {}

// Member function to calculate area
double Circle::calculateArea() const {
  return 3.14159 * radius * radius; // Assuming pi as 3.14159
}

// Getter functions
double Circle::getX() const { return x; }

double Circle::getY() const { return y; }

double Circle::getRadius() const { return radius; }
