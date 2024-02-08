// circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    double x;
    double y;
    double radius;

public:
    // Constructor
    Circle(double x, double y, double radius);

    // Member function to calculate area
    double calculateArea() const;

    // Getter functions
    double getX() const;
    double getY() const;
    double getRadius() const;
};

#endif // CIRCLE_H
