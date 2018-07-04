#include "Shape.h"

Shape::Shape(std::string type):m_type(type)
{
}

std::string Shape::getType(){
    return m_type;
}

double Shape::getPerimeter(){
    return 0;
}

double Shape::getArea(){
    return 0;
}
