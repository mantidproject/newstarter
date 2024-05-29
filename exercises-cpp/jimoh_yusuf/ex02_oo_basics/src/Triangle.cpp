//
// Created by gfl56326 on 29/05/2024.
//

#include "Triangle.h"

Triangle::Triangle(double h, double b) : height(h), base(b) {
    number_of_sides = 3;
}

std::string Triangle::getType() {
    return "Triangle";
}

double Triangle::calculatePerimeter() {
    double perimeter = base + 2 * sqrt(height * height + (base * base / 4));
    std::cout << "The perimeter of the triangle is " << perimeter << std::endl;
    return perimeter;
}

double Triangle::calculateArea() {
    double area = 0.5 * base * height;
    std::cout << "The area of the triangle is " << area << std::endl;
    return area;
}

int Triangle::getNumberOfSides() {
    return number_of_sides;
}

