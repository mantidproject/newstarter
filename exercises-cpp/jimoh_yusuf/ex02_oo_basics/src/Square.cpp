//
// Created by gfl56326 on 29/05/2024.
//

#include "Square.h"

Square::Square(double side) : side1(side) {
    number_of_sides = 4;
}

std::string Square::getType() {
    return "Square";
}

double Square::calculatePerimeter() {
    double perimeter = 4 * side1;
    return perimeter;
}

double Square::calculateArea() {
    double area = side1 * side1;
    return area;
}

int Square::getNumberOfSides() {
    return number_of_sides;
}

