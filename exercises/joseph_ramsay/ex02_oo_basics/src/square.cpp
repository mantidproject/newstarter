#include "square.h"


Square::Square(int sideLength): Rectangle(sideLength, sideLength) {};


ShapeType Square::getType() const{
  return T_square;
}


std::string Square::toString() const{
  return std::string("square(side=") + std::to_string(m_side1Length) + ")";
}
