#include "Circle.h"

Circle::Circle(double radius)
    : m_radius(radius), m_area(3.14159 * radius * radius),
      m_perimeter(2.0 * 3.14159 * radius) {}

std::string Circle::getType() const { return "Circle"; }

std::size_t Circle::getNumberOfEdges() const { return 1; }

double Circle::getPerimeter() const { return m_perimeter; }

double Circle::getArea() const { return m_area; }
