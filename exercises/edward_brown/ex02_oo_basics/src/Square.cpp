#include "Square.h"
#include <cmath>
#include <ostream>

Square::Square(double SideLength) : m_SideLength(SideLength) {}

ShapeType Square::getShapeType() const { return ShapeType::Square; }

int Square::getSideCount() const { return 4; }

double Square::getPerimeter() const { return getSideLength() * getSideCount(); }

double Square::getArea() const { return std::pow(getSideLength(), 2.0); }

void Square::printAttributes(std::ostream &OutputStream) const {
  OutputStream << "SideLength: " << getSideLength();
}

double Square::getSideLength() const { return m_SideLength; }
