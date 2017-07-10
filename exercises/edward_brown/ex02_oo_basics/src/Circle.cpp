#include "Circle.h"
#include <ostream>
#include <cmath>

Circle::Circle(double Radius) : m_Radius(Radius) {}

std::string Circle::getShapeName() const {
  return std::string("Circle");
}

int Circle::getSideCount() const {
  return 1;
}

double Circle::getPerimeter() const {
  return getDiameter() * PI;
}

double Circle::getDiameter() const {
  return getRadius() * 2;
}

double Circle::getArea() const {
  PI * std::pow(getRadius(), 2.0);
}

double Circle::getRadius() const {
  return m_Radius;
}

void Circle::printAttributes(std::ostream& OutputStream) const {
  OutputStream << "Radius: " << getRadius();
}