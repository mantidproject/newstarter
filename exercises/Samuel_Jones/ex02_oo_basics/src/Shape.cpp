#include "Shape.h"

Shape::Shape(std::string type) : m_type(type) {}

std::string Shape::getType() const { return m_type; }

double Shape::getPerimeter() const { return 0; }

double Shape::getArea() const { return 0; }
