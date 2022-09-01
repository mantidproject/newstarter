#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double radius_i);
    double perimeter();
    double area();
    void print();
};

#endif