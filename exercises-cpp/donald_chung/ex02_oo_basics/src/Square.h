#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{
private:
    double side;
public:
    Square(double side_i);
    double perimeter();
    double area();
    void print();
};

#endif