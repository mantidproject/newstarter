#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"
#include "math.h"

class Triangle : public Shape
{
private:
    int m_height;
    int m_base;
public:
    Triangle(int, int);
    double getPerimeter();
    double getArea();
};

#endif /*TRIANGLE_H_*/