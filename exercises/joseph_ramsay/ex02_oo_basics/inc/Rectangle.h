#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {

protected:
  int m_side1Length, m_side2Length;

public:
  Rectangle(int side1Length, int side2Length);
  int getNumSides() const override;
  double getArea() const override;
  double getPerimeter() const override;
  ShapeType getType() const override;
  std::string toString() const override;
};

#endif
