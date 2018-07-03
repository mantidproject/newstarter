#include "Shape.h"
#include "Circle.h"

Circle::Circle(int radius):m_radius(radius)
{
}

float Circle::getPerimeter(){
    return 2*pi*m_radius;
}

float Circle::getArea(){
    return pi*(m_radius*m_radius);
}