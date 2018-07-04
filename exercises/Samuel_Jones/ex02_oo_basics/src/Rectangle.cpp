#include "Rectangle.h"

Rectangle::Rectangle(int side1, int side2):Shape("Rectangle"), m_side1(side1), m_side2(side2)
{
}

double Rectangle::getPerimeter() const{
    return m_side1*2 + m_side2*2;
}

double Rectangle::getArea() const{
    return m_side1*m_side2;
}