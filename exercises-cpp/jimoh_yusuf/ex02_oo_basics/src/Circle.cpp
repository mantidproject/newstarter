//
// Created by gfl56326 on 29/05/2024.
//

#include "Circle.h"

Circle::Circle(double r) : radius(r) {
    number_of_sides = 0;
}

std::string Circle::getType() {
    return "Circle";
}

double Circle::calculatePerimeter() {
    double perimeter = 2 * M_PI * radius;
    return perimeter;
}

double Circle::calculateArea() {
    double area = M_PI * radius * radius;
    return area;
}

int Circle::getNumberOfSides() {
    return number_of_sides;
}

