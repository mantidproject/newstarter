#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape
{
private:
    int m_side1;
    int m_side2;
public:
    Rectangle(int, int);
    int getPerimeter();
    int getArea();
};

#endif /*RECTANGLE_H_*/