// circle_test.cpp
#include <iostream>
#include "circle.h"

int main() {
    // Creating a circle object with parameters
    Circle myCircle(2.0, 3.0, 4.0);

    // Accessing and displaying the parameters
    std::cout << "Circle Information:" << std::endl;
    std::cout << "X-coordinate: " << myCircle.getX() << std::endl;
    std::cout << "Y-coordinate: " << myCircle.getY() << std::endl;
    std::cout << "Radius: " << myCircle.getRadius() << std::endl;

    // Calculating and displaying the area
    std::cout << "Area: " << myCircle.calculateArea() << std::endl;

    return 0;
}
