//
// Created by gfl56326 on 29/05/2024.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <iostream>
#include <string>
#include <cmath>

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius);

    std::string getType() override;
    double calculatePerimeter() override;
    double calculateArea() override;
    int getNumberOfSides() override;
};

#endif // CIRCLE_H

