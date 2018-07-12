#include "Triangle.h"

Triangle::Triangle(double base, double height)
    : m_base(base), m_height(height), m_area(0.5 * base * height),
      m_perimeter(base + 2 * std::sqrt(height * height + (base * base / 4))) {}

double Triangle::getBase() const { return m_base; }

double Triangle::getHeight() const { return m_height; }

std::string Triangle::getType() const { return "Triangle"; }

std::size_t Triangle::getNumberOfEdges() const { return 3; }

double Triangle::getArea() const { return m_area; }

double Triangle::getPerimeter() const { return m_perimeter; }
