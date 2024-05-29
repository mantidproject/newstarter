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
    std::cout << "The perimeter of the square is " << perimeter << std::endl;
    return perimeter;
}

double Square::calculateAreaa() {
    double area = side1 * side1;
    std::cout << "The area of the square is " << area << std::endl;
    return area;
}

int Square::getNumberOfSides() {
    return number_of_sides;
}

