#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {

private:
  int m_height, m_base;

public:
  Triangle(int height, int base);
  int getNumSides() const override;
  double getArea() const override;
  double getPerimeter() const override;
  ShapeType getType() const override;
  std::string toString() const override;
};

#endif
