#include "Square.h"

Square::Square(int sideLength) : Rectangle(sideLength, sideLength){};

ShapeType Square::getType() const { return ShapeType::square; }

std::string Square::toString() const {
  return std::string("square(side=") + std::to_string(m_side1Length) + ")";
}
