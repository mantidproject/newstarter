#include "Circle.h"

#include <cmath>

Circle::Circle(double radius)
    : m_radius(radius), m_area(M_PI * radius * radius),
      m_perimeter(2.0 * M_PI * radius) {}

std::string Circle::getType() const { return "circle"; }

std::size_t Circle::getNumberOfEdges() const { return 1; }

double Circle::getPerimeter() const { return m_perimeter; }

double Circle::getArea() const { return m_area; }
