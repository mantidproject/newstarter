#include "Rectangle.h"

Rectangle::Rectangle(int side1, int side2):m_side1(side1), m_side2(side2), Shape("Rectangle")
{
}

float Rectangle::getPerimeter(){
    return m_side1*2 + m_side2*2;
}

float Rectangle::getArea(){
    return m_side1*m_side2;
}