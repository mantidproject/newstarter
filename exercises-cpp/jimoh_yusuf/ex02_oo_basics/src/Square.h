//
// Created by gfl56326 on 29/05/2024.
//

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <iostream>
#include <string>
using namespace std;

class Square : public Shape {
private:
    double side1;
public:
    Square(double side);

    std::string getType() override;
    double calculatePerimeter() override;
    double calculateArea() override;
    int getNumberOfSides() override;
};

#endif // SQUARE_H


