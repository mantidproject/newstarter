//
// Created by gfl56326 on 29/05/2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <iostream>
#include <string>

class Rectangle : public Shape {
private:
    double side1, side2;

public:
    Rectangle(double side1, double side2);

    std::string getType() override;
    double calculatePerimeter() override;
    double calculateArea() override;
    int getNumberOfSides() override;
};

#endif // RECTANGLE_H
