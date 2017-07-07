#include <math.h>
#include "circle.h"


Circle::Circle(int radius): m_radius(radius) {};


int Circle::getNumSides() const{
  return 1;
}


double Circle::getArea() const{
  return M_PI * m_radius * m_radius;
}


double Circle::getPerimeter() const{
  return M_PI * 2 * m_radius;
}


ShapeType Circle::getType() const{
  return T_circle;
}


std::string Circle::toString() const{
  return std::string("circle(radius=") + std::to_string(m_radius) + ")";
}
