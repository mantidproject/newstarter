#include "Square.h"

Square::Square(int side1):m_side1(side1), Shape("Square")
{
}

int Square::getPerimeter(){
    return m_side1*4;
}

int Square::getArea(){
    return m_side1*m_side1;
}