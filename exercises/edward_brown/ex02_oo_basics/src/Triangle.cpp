#include "Triangle.h"
#include <cmath>
#include <ostream>

Triangle::Triangle(double Base, double Height)
    : m_Base(Base), m_Height(Height) {}

ShapeType Triangle::getShapeType() const { return ShapeType::Triangle; }

int Triangle::getSideCount() const { return 3; }

double Triangle::getPerimeter() const {
  return getBase() + (2.0 * std::hypot(getBase() / 2.0, getHeight()));
}

double Triangle::getArea() const { return getBase() * getHeight() / 2.0; }

void Triangle::printAttributes(std::ostream &OutputStream) const {
  OutputStream << "Base: " << getBase() << ", Height: " << getHeight();
}

double Triangle::getBase() const { return m_Base; }

double Triangle::getHeight() const { return m_Height; }
