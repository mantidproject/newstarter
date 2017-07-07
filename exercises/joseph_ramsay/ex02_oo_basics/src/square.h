#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {

public:
  Square(int sideLength);
  ShapeType getType() const;
  std::string toString() const;
};

#endif
