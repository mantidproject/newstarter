#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
private:
    double base, height;
public:
    Triangle(double base, double height);
    double perimeter();
    double area();
    void print();
};

#endif