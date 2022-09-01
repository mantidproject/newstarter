#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
    double len, wid;
public:
    Rectangle(double len_i, double wid_i);
    double perimeter();
    double area();
    void print();
};

#endif