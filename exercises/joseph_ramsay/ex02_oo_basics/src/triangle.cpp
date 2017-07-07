#include <cmath>
#include "triangle.h"


Triangle::Triangle(int height, int base): m_height(height), m_base(base) {};


int Triangle::getNumSides() const{
  return 3;
}


double Triangle::getArea() const{
  return m_base * m_height / 2.;
}


double Triangle::getPerimeter() const{
  return m_base + 2. * std::sqrt(m_height * m_height + (m_base * m_base / 4));
}


ShapeType Triangle::getType() const{
  return T_triangle;
}


std::string Triangle::toString() const{
  return std::string("triangle(base=") + std::to_string(m_base) + ", height=" + std::to_string(m_height) + ")";
}
