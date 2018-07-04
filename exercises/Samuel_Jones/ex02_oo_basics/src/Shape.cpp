#include "Shape.h"

Shape::Shape(std::string type):m_type(type)
{
}

std::string Shape::getType(){
    return m_type;
}

float Shape::getPerimeter(){
    return 0;
}

float Shape::getArea(){
    return 0;
}
