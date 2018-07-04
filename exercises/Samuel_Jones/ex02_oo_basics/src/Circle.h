#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle : public Shape
{
private:
    int m_radius;
public:
    Circle(int);
    double getPerimeter();
    double getArea();
};

constexpr auto pi = 3.14159265358979323846;

#endif /*CIRCLE_H_*/