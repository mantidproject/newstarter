#include "rectangle.h"

Rectangle::Rectangle(int side1Length, int side2Length)
    : m_side1Length(side1Length), m_side2Length(side2Length){};

int Rectangle::getNumSides() const { return 4; }

double Rectangle::getArea() const { return m_side1Length * m_side2Length; }

double Rectangle::getPerimeter() const {
  return 2 * m_side1Length + 2 * m_side2Length;
}

ShapeType Rectangle::getType() const { return T_rectangle; }

std::string Rectangle::toString() const {
  return std::string("rectangle(side1=") + std::to_string(m_side1Length) +
         ", side2=" + std::to_string(m_side2Length) + ")";
}
