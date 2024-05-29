//
// Created by gfl56326 on 29/05/2024.
//

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

class Shape {
protected:
    int number_of_sides;

public:
    virtual std::string getType() = 0;
    virtual double calculatePerimeter() = 0;
    virtual double calculateArea() = 0;
    virtual int getNumberOfSides() = 0;
    virtual ~Shape() = default;
};

#endif //SHAPE_H
