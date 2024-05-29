//
// Created by gfl56326 on 29/05/2024.
//

#include "Rectangle.h"

Rectangle::Rectangle(double s1, double s2) : side1(s1), side2(s2) {
    number_of_sides = 4;
}

std::string Rectangle::getType() {
    return "Rectangle";
}

double Rectangle::calculatePerimeter() {
    double perimeter = 2 * (side1 + side2);
    std::cout << "The perimeter of the rectangle is " << perimeter << std::endl;
    return perimeter;
}

double Rectangle::calculateArea() {
    double area = side1 * side2;
    std::cout << "The area of the rectangle is " << area << std::endl;
    return area;
}

int Rectangle::getNumberOfSides() {
    return number_of_sides;
}

