#include "Shape.h"
#include "Circle.h"

Circle::Circle(int radius):m_radius(radius), Shape("Circle")
{  
}

double Circle::getPerimeter()const{
    return 2*pi*m_radius;
}

double Circle::getArea()const{
    return pi*(m_radius*m_radius);
}