#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {

public:
  Square(int sideLength);
  ShapeType getType() const override;
  std::string toString() const override;
};

#endif
