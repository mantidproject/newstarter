//
// Created by gfl56326 on 29/05/2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <iostream>
#include <string>
#include <cmath>

class Triangle : public Shape {
private:
    double height, base;

public:
    Triangle(double height, double base);

    std::string getType() override;
    double calculatePerimeter() override;
    double calculateArea() override;
    int getNumberOfSides() override;
};

#endif // TRIANGLE_H
