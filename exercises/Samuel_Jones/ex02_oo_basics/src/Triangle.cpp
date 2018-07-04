#include "Triangle.h"

Triangle::Triangle(int base, int height):m_base(base), m_height(height), Shape("Triangle")
{
}

double Triangle::getPerimeter()const{
    return m_base + 2*(sqrt((m_height*m_height)+((m_base*m_base)/4)));
}

double Triangle::getArea()const{
    return (m_base*m_height)/2;
}