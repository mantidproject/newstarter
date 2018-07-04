#include "Square.h"

Square::Square(int side1):m_side1(side1), Shape("Square")
{
}

float Square::getPerimeter(){
    return m_side1*4;
}

float Square::getArea(){
    return m_side1*m_side1;
}
