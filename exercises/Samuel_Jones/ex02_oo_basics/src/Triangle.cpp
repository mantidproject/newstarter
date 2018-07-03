#include "Triangle.h"

Triangle::Triangle(int base, int height):m_base(base), m_height(height), Shape("Triangle")
{
}

float Triangle::getPerimeter(){
    return m_base + 2*(sqrt((m_height*m_height)+((m_base*m_base)/4)));
}

float Triangle::getArea(){
    return (m_base*m_height)/2;
}