#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {

private:
  int m_height, m_base;

public:
  Triangle(int height, int base);
  int getNumSides() const;
  double getArea() const;
  double getPerimeter() const;
  ShapeType getType() const;
  std::string toString() const;
};

#endif
