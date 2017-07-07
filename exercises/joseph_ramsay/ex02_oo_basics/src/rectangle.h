#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {

protected:
  int m_side1Length, m_side2Length;

public:
  Rectangle(int side1Length, int side2Length);
  int getNumSides() const;
  double getArea() const;
  double getPerimeter() const;
  ShapeType getType() const;
  std::string toString() const;
};

#endif
