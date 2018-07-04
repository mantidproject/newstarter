#include "Square.h"

Square::Square(int side1): Shape("Square"), m_side1(side1)
{
}

double Square::getPerimeter() const{
    return m_side1*4;
}

double Square::getArea()const{
    return m_side1*m_side1;
}
